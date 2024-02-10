#!/usr/bin/python3
def add_tuple(tuple_a=(), tuple_b=()):
    Ttuple = tuple(())

    for num in range(2):
        if len(tuple_a) < 2:
            tuple_a += (0),
        if len(tuple_b) < 2:
            tuple_b += (0),
    
    for num in range(2):
        Ttuple += (int(tuple_a[num]) + int(tuple_b[num])),
    return Ttuple