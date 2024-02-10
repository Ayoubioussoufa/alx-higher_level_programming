#!/usr/bin/python3
def roman_to_int(roman_string):
    if type(roman_string) is not str or roman_string is None:
        return None
    dicts = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }
    result = 0
    deck = [dicts[x] for x in roman_string]
    for num in range(len(deck)):
        result += deck[num]
        if deck[num - 1] < deck[num] and num != 0:
            result -= deck[num - 1] + deck[num - 1]
    return result