from cs50 import get_string

def count_letters(text):
    letters = 0
    for ch in text:
        if ch.isalpha():
            letters += 1
    return letters

def count_words(text):
    words = 1
    for ch in text:
        if ch.isspace():
            words += 1
    return words

def count_sentences(text):
    sentences = 0
    for sentence in text:
        if sentence == '.' or sentence == '?' or sentence == '!':
            sentences += 1
    return sentences

text = get_string("Text: ")

letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)


if letters == 0:
    print("This text does not contain any letters.")

l = letters/words * 100.00
s = sentences/words * 100.00

index = (0.0588 * l - 0.296 * s - 15.8)

grade = round(index)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print (f"Grade {grade}")

