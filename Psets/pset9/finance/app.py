import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # All purchases history
    portfolio_db = db.execute("SELECT symbol, name, shares FROM portfolio WHERE user_id = ?", session["user_id"])

    # list of dictionaries that will display in index.html
    portfolio = []

    # Sum of total stocks
    total_sum = 0

    # Update each purchase's price if user has shares of it and add it to total_sum
    for purchase in portfolio_db:
        if purchase["shares"] != 0:
            symbol = str(purchase["symbol"])
            shares = int(purchase["shares"])
            price = lookup(symbol)["price"]
            purchase["price"] = price
            total = shares * price
            purchase["total_value"] = total
            total_sum += float(total)
            portfolio.append(purchase)

    # User's current cash balance
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

    # Total value of stocks and cash together
    total_cash = cash + total_sum

    return render_template("index.html", portfolio=portfolio, cash=cash, total_cash=total_cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        # Ensure symbol was provided
        if not request.form.get("symbol"):
            return apology("You must provide a symbol", 400)

        # Ensure shares were provided and right number
        if not request.form.get("shares"):
            return apology("You must provid the number of shares", 400)

        # Get shares
        try:
            shares = int(request.form.get("shares"))
        except ValueError:
            return apology("invalid number of shares", 400)

        if shares < 0:
            return apology("invalid number of shares", 400)

        # Get stock symbol
        symbol = request.form.get("symbol").upper()

        # Get stock quote
        quote = lookup(symbol)

        # if stock symbol exists
        if quote != None:

            # Get user id
            user_id = session["user_id"]

            # Get stock price
            currentPrice = quote["price"]

            companyName = quote["name"]

            # Calculate purchase value
            purchase_value = shares * currentPrice

            # Get the cash user have yet
            user_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
            cash = float(user_cash[0]["cash"])

            # If cash is grather than or equal to the purchase value:
            if purchase_value <= cash:

                # Get the time
                date = datetime.datetime.now()

                # Update cash in database
                cash = cash - purchase_value
                db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, user_id)

                # Insert the purchase data indo history database
                db.execute("INSERT INTO purchases (user_id, symbol,name, shares, price, total_value, date, operation) VALUES (?, ?, ?, ?, ?, ?, ?, 'BUY')",
                           user_id, symbol, companyName, shares, currentPrice, purchase_value, date)

                # Update portfolio
                if db.execute("SELECT COUNT(1) from portfolio WHERE user_id = ? AND symbol = ?", user_id, symbol)[0]["COUNT(1)"] == 1:
                    db.execute("UPDATE portfolio SET shares = shares + ? WHERE user_id = ? AND symbol = ?", shares, user_id, symbol)
                else:
                    db.execute("INSERT INTO portfolio (symbol, name, price, total_value, shares, user_id) VALUES (?, ?, ?, ?, ?, ?)",
                               symbol, companyName, currentPrice, purchase_value, shares, user_id)

                flash("Bought!")
                return redirect("/")
            else:
                return apology("not enough cash", 400)

        else:
            return apology("stock symbol doesn't exist", 400)

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    purchases = db.execute("SELECT * FROM purchases ORDER BY date DESC")

    return render_template("history.html", purchases=purchases)


@app.route("/change_password", methods=["GET", "POST"])
@login_required
def change_password():
    """Change accont's password"""
    if request.method == "POST":

        user_id = session["user_id"]
        # Get the data from form
        old_password = request.form.get("old_password")
        new_password = request.form.get("new_password")
        confirmation = request.form.get("confirmation")

        # Check for input errors
        if not old_password:
            return apology("must provide the old password", 400)

        elif not new_password:
            return apology("must provide the new password", 400)

        if not confirmation:
            return apology("must provide the new password again", 400)

        # Check wether the old password is correct
        user_hash = db.execute("SELECT hash FROM users WHERE id = ?", user_id)[0]["hash"]

        if check_password_hash(user_hash, old_password) == False:
            return apology("old password is incorrect", 400)

        # Check if new password and confirmation match
        if new_password != confirmation:
            return apology("new password and confirmation password doesn't match", 400)

        new_hash = generate_password_hash(new_password)

        db.execute("UPDATE users SET hash = ? WHERE id = ?", new_hash, user_id)

        flash("Password successfully changed!")

        return redirect("/")
    else:
        return render_template("change_password.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    if request.method == "POST":

        # Ensure symbol was provided
        if not request.form.get("symbol"):
            return apology("You must provide a symbol", 400)

        # Get stock symbol
        stockSymbol = request.form.get("symbol")

        # Get stock quote
        stockQuote = lookup(stockSymbol)

        # if stock symbol exists
        if stockQuote != None:

            # Get company's name
            companyName = stockQuote["name"]

            # Get stock price
            lastestPrice = stockQuote["price"]

            # Get stock symbol
            symbol = stockQuote["symbol"]

            # render quoted template with the data
            return render_template("quoted.html", companyName=companyName, lastestPrice=lastestPrice, symbol=symbol)
        else:
            return apology("stock symbol doesn't exist", 400)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":

        # Ensure username was submited
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submited
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Ensure password and confirmation match
        if request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords doesn't match", 400)

        # Try to register user into database
        try:
            # Hash password
            hashed_pswd = generate_password_hash(request.form.get("password"))

            # Register into database
            new_user = db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", request.form.get("username"), hashed_pswd)
        except:
            return apology("username already taken", 400)

        # Log user in
        session["user_id"] = new_user

        flash("Registered!")

        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        # Ensure symbol was provided and get symbol
        if not request.form.get("symbol"):
            return apology("You must provide a symbol", 400)

        symbol = request.form.get("symbol")
        stock = lookup(symbol)["price"]
        company_name = lookup(symbol)["name"]

        # Get user id
        user_id = session["user_id"]

        # Ensure shares were provided and get shares
        if not request.form.get("shares"):
            return apology("You must provide shares", 400)

        shares = int(request.form.get("shares"))

        # Ensure that the user has enough shares that they want to sell
        user_shares = db.execute("SELECT shares FROM portfolio WHERE user_id = ? AND symbol = ?", user_id, symbol)[0]["shares"]

        if shares > user_shares:
            return apology("you don't have this number of shares of this stock", 400)

        # Insert operation data into history database
        total_value = stock * shares

        date = datetime.datetime.now()

        db.execute("INSERT INTO purchases (user_id, symbol, name, shares, price, total_value, date, operation) VALUES (?, ?, ?, ?, ?, ?, ?, 'SELL')",
                   user_id, symbol, company_name, shares, stock, total_value, date)

        # Update portfolio
        db.execute("UPDATE portfolio SET shares = shares - ? WHERE user_id = ? AND symbol = ? ", shares, user_id, symbol)
        db.execute("DELETE FROM portfolio WHERE shares = 0")

        # Update cash in users
        cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]

        db.execute("UPDATE users SET cash = ? * ? + ? WHERE id = ?", stock, shares, cash, user_id)

        flash("Sold!")

        return redirect("/")
    else:
        symbols = db.execute("SELECT DISTINCT symbol FROM portfolio WHERE user_id = ?", session["user_id"])

        return render_template("sell.html", symbols=symbols)
