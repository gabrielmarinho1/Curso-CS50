# TODO
from cs50 import get_string


# get text and the text length
text = get_string("Text: ")
txt_len = len(text)

# variables initialization
letters = 0
words = 1
sentences = 0

# count letters at each alphabetical character, words at each space and sentences at each '.', '!' or '?'
for char in text:
    if char.isalpha():
        letters += 1
    elif char.isspace():
        words += 1
    elif char == '.' or char == '!' or char == '?':
        sentences += 1

# average number of letters per 100 words
l = letters / words * 100

# average number of sentences per 100 words
s = sentences / words * 100

# Coleman-Liau index
index = round(0.0588 * l - 0.296 * s - 15.8)

# check whether grade the text is
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")