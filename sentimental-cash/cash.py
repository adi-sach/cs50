from cs50 import get_float
import math

while True:
    change = get_float("Change: ")
    if change >= 0:
        break

change *= 100

coins = 0

while change > 0:
    if change >= 25:
        change -= 25
        coins += 1
    elif change >= 10:
        change -= 10
        coins += 1
    elif change >= 5:
        change -= 5
        coins += 1
    else:
        change -= 1
        coins += 1

print (coins)
