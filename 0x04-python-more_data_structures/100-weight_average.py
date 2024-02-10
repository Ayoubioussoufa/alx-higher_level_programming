#!/usr/bin/python3
def weight_average(my_list=[]):
    if len(my_list) == 0:
        return 0
    weight = 0
    score = 0
    for num in my_list:
        x, y = num
        score += x * y
        weight += y
    return score / weight
