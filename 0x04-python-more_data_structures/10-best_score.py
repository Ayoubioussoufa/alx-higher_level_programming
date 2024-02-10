#!/usr/bin/python3
def best_score(a_dictionary):
    if not a_dictionary:
        return (None)
    a_dictionary = dict(sorted(a_dictionary.items(), key=lambda x : x[1]))
    item, W = list(a_dictionary.items())[-1]
    return item
