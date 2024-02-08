#!/usr/bin/python3
def print_last_digit(number):
    if number < 10:
        number *= -1
    print(number % 10, end="")
    return number % 10