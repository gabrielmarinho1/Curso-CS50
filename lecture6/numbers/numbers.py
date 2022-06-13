import sys

numbers = [2, 4, 5, 7, 3, 1, 0]

if 0 in numbers:
    print("Found!")
    sys.exit(0)

print("Not found.")
sys.exit(1)