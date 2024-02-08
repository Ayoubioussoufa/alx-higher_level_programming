#!/usr/bin/python3
for num in range(0, 9):
    for scd in range(num + 1, 10):
        if scd == 9 and num == 8:
            print("{:d}{:d}".format(num, scd))
        else:
            print("{:d}{:d}".format(num, scd), end=", ")
