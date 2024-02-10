#!/usr/bin/python3
def divisible_by_2(my_list=[]):
    lists = []
    for num in my_list:
        if num % 2 == 0:
            lists.append(True)
        else:
            lists.append(False)
    return lists
