# TODO

from cs50 import get_int

# get height from 1 to 8
while True:
    height = get_int("Height: ")
    if height > 0 and height <= 8:
        break

# print pyramid
for hash in range(1, height + 1):
    print(" " * int(height - hash), end="")
    print("#" * hash, end="")
    print("  ", end="")
    print("#" * hash)