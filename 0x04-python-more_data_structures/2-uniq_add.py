#!/usr/bin/python3
def uniq_add(my_list=[]):
    lists = []
    addition = 0
    for x in my_list:
        if x not in lists:
            addition += x
            lists.append(x)
    return addition
