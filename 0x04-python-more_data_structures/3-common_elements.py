#!/usr/bin/python3
def common_elements(set_1, set_2):
    sets = set()
    for first in set_1:
        for second in set_2:
            if (first == second):
                sets = {first}
    return sets
    # or simply return (set_1 & set_2)
