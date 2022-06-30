-- Keep a log of any SQL queries you execute as you solve the mystery.

/* with this query i discovered that the theft happend at 10:15am at the Humphrey Street bakery and there was 3 witnesses*/
SELECT  description
FROM    crime_scene_reports
WHERE
    day = 28 AND
    month = 7 AND
    year = 2021 AND
    street = "Humphrey Street";

/* with this i saw the witnesses interviews*/
SELECT
    name,
    transcript
FROM    interviews
WHERE
    day = 28 AND
    month = 7 AND
    year = 2021;
/* Eugene, Raymond and Ruth*/

/* who got out of the bakery within 10 minutes*/
SELECT *
FROM    people
    INNER JOIN  bakery_security_logs
    ON  bakery_security_logs.license_plate = people.license_plate
WHERE
    day = 28 AND
    month = 7 AND
    year = 2021 AND
    hour = 10 AND
    minute BETWEEN 15 AND 25;
/* Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana and Kelsey*/

/* every withdraw made in that day*/
SELECT
    atm_transactions.id,
    atm_transactions.account_number,
    atm_location,
    transaction_type,
    amount,
    name
FROM    atm_transactions
    INNER JOIN  bank_accounts
    ON  bank_accounts.account_number = atm_transactions.account_number
    INNER JOIN  people
    ON   bank_accounts.person_id = people.id
WHERE
    day = 28 AND
    month = 7 AND
    year = 2021 AND
    transaction_type = "withdraw" AND
    atm_location = "Leggett Street"
ORDER BY
    atm_transactions.id;
/*Luca, Kenny, Taylor, Bruce, Brooke, Iman, Benista, Diana*/

/* according to Raymond, the thief called the accomplice*/
SELECT  *
FROM    phone_calls
    INNER JOIN  people
    ON   phone_calls.caller = people.phone_number
WHERE
    day = 28 AND
    month = 7 AND
    duration <= 60 AND
    year = 2021;
/*Sofia->Jack, Kelsey->Larry, Bruce->Robin, Kathryn->Luca, Kelsey->Melissa, Taylor->James, Diana->Philip, Carina->Jacqueline, Kenny->Doris, Benista->Anna*/

/* flight the thief took in next day*/
SELECT
    flights.id,
    origin_airport_id,
    destination_airport_id
FROM    flights
    INNER JOIN  airports
    ON  flights.origin_airport_id = airports.id
WHERE
    city = "Fiftyville" AND
    day = 29 AND
    month = 7 AND
    year = 2021
ORDER BY    hour
LIMIT   1;

/* city the thief escaped to*/
SELECT  *
FROM    airports
WHERE
    id IN (
        SELECT  destination_airport_id
        FROM    flights
            INNER JOIN  airports
            ON  flights.origin_airport_id = airports.id
        WHERE
            city = "Fiftyville" AND
            day = 29 AND
            month = 7 AND
            year = 2021
        ORDER BY    hour
        LIMIT   1
    );
/*New York City*/

/* all people that flew to New York from Fiftyville the next day*/
SELECT  *
FROM passengers
    INNER JOIN  people
    ON  passengers.passport_number = people.passport_number
WHERE
    passengers.flight_id IN(
        SELECT
            flights.id
        FROM    flights
            INNER JOIN  airports
            ON  flights.origin_airport_id = airports.id
        WHERE
            city = "Fiftyville" AND
            day = 29 AND
            month = 7 AND
            year = 2021
        ORDER BY    hour
        LIMIT   1
    );
/*Doris, Sofia, Bruce, Edward, Kelsey, Taylor, Kenny and Luca*/

/* people that were in the bakery while the theft happend and also took the flight to New York next day*/
SELECT *
FROM    people
    INNER JOIN  bakery_security_logs
    ON  bakery_security_logs.license_plate = people.license_plate
WHERE
    day = 28 AND
    month = 7 AND
    year = 2021 AND
    hour = 10 AND
    name IN (
        SELECT  people.name
        FROM passengers
            INNER JOIN  people
            ON  passengers.passport_number = people.passport_number
        WHERE
            passengers.flight_id IN(
                SELECT
                    flights.id
                FROM    flights
                    INNER JOIN  airports
                    ON  flights.origin_airport_id = airports.id
                WHERE
                    city = "Fiftyville" AND
                    day = 29 AND
                    month = 7 AND
                    year = 2021
                ORDER BY    hour
                LIMIT   1
            )
    );
/*Bruce, Luca, Sofia, Kelsey and Taylor*/

/* people that made a withdraw in the day the theft happend and took the flight to New York the next day*/
SELECT
    atm_transactions.id,
    atm_transactions.account_number,
    atm_location,
    transaction_type,
    amount,
    name
FROM    atm_transactions
    INNER JOIN  bank_accounts
    ON  bank_accounts.account_number = atm_transactions.account_number
    INNER JOIN  people
    ON   bank_accounts.person_id = people.id
WHERE
    day = 28 AND
    month = 7 AND
    year = 2021 AND
    transaction_type = "withdraw" AND
    atm_location = "Leggett Street" AND
    people.name IN (
        SELECT  people.name
        FROM passengers
            INNER JOIN  people
            ON  passengers.passport_number = people.passport_number
        WHERE
            passengers.flight_id IN(
                SELECT
                    flights.id
                FROM    flights
                    INNER JOIN  airports
                    ON  flights.origin_airport_id = airports.id
                WHERE
                    city = "Fiftyville" AND
                    day = 29 AND
                    month = 7 AND
                    year = 2021
                ORDER BY    hour
                LIMIT   1
            )
    )
ORDER BY
    atm_transactions.id;
/*Luca, Kenny, Taylor and Bruce*/

/* people that made and received a call in less than a minute that day and flew to NY the next day*/
SELECT  *
FROM    phone_calls
    INNER JOIN  people
    ON   phone_calls.receiver = people.phone_number
WHERE
    day = 28 AND
    month = 7 AND
    duration <= 60 AND
    year = 2021 AND
    name IN (
        SELECT  people.name
        FROM passengers
            INNER JOIN  people
            ON  passengers.passport_number = people.passport_number
        WHERE
            passengers.flight_id IN(
                SELECT
                    flights.id
                FROM    flights
                    INNER JOIN  airports
                    ON  flights.origin_airport_id = airports.id
                WHERE
                    city = "Fiftyville" AND
                    day = 29 AND
                    month = 7 AND
                    year = 2021
                ORDER BY    hour
                LIMIT   1
            )
    );
/*Sofia, Kelsey, Bruce, Kelsey Taylor and Kenny*/

/* Bruce appears to be the thief because he matches all the lists and Robin appears to be the accomplice because Bruce
called her and flew her to NYC*/