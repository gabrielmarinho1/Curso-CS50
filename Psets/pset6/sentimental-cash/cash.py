# TODO
from cs50 import get_float

while True:
    change = get_float("Change owed: ") * 100
    if change > 0:
        break

coins = 0

while True:
    if change >= 25:
        change -= 25
        coins += 1
    else:
        break
while True:
    if change >= 10:
        change -= 10
        coins += 1
    else:
        break
while True:
    if change >= 5:
        change -= 5
        coins += 1
    else:
        break
while True:
    if change >= 1:
        change -= 1
        coins += 1
    else:
        break

print(f"{coins}")