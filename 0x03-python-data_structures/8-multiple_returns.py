#!/usr/bin/python3
def multiple_returns(sentence):
    if (sentence == ""):
        tuples = 0, None
    else:
        tuples = len(sentence), sentence[0]
    return tuples
