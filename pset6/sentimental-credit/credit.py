# TODO
from cs50 import get_string


# use the algorithm to validade card number
def validade_number(number):
    tmp1 = number
    tmp2 = tmp1
    sum = 0
    # first part
    while tmp1 > 0:
        tmp1 = tmp1 // 10
        if tmp1 % 10 * 2 > 9:
            for digit in str(tmp1 % 10 * 2):
                sum += int(digit)
        else:
            sum += (tmp1 % 10) * 2
        tmp1 = tmp1 // 10

    # second part
    while tmp2 > 0:
        sum += tmp2 % 10
        tmp2 = tmp2 // 100

    # check wether the the final sum is divisible by 10
    if sum % 10 == 0:
        return True
    else:
        return False


# get the card number
while True:
    number = get_string("Number: ")
    if len(number) == 13 or len(number) == 15 or len(number) == 16:
        if validade_number(int(number)) == True:
            break
    else:
        print("INVALID")
        exit()

# get the 1st and the 2nd digits of the card number
fst_digit = int(number[0])
snd_digit = int(number[1])

# if it's Visa
if len(number) == 13 and fst_digit == 4:
    print("VISA")

# if it's Amex
elif len(number) == 15 and fst_digit == 3:
    if snd_digit == 4 or snd_digit == 7:
        print("AMEX")

# if it's Mastercard or Visa
elif len(number) == 16:
    if fst_digit == 5:
        for i in [1, 2, 3, 4, 5]:
            if snd_digit == i:
                print("MASTERCARD")
    elif fst_digit == 4:
        print("VISA")
else:
    print("INVALID")