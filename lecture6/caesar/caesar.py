from sys import argv

# Get the key
if len(argv) == 2 and argv[1].isdigit():
    key = int(argv[1])
else:
    print("Usage: python caesar.py KEY")
    exit(1)

# Get the plaintext
plaintext = input("Plaintext: ")

# Print the "Ciphertext: " and than print the enciphered text
print("Ciphertext: ", end="")
for char in plaintext:  # For each char in plaintext
    
    if char.isupper():  # If char is uppercase
        print(chr((ord(char) - 65 + key) % 26 + 65), end="")  # Print it applying the key

    elif char.islower():  # If char is lowercase
        print(chr((ord(char) - 97 + key) % 26 + 97), end="")  # Print it applying the key

    else:  # If char is not a letter
        print(char, end="")  # Just print it

print("")  # Print new line at the end