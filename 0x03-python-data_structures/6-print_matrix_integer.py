#!/usr/bin/python3
def print_matrix_integer(matrix=[[]]):
    for num in matrix:
        for row in num:
            print("{:d}".format(row), end=" ")
        print()
