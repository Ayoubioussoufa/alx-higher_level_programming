#!/usr/bin/python3
from sys import argv
if __name__ == "__main__":
    num_of_arguments = len(argv) - 1
    if num_of_arguments:
        print(len(argv) - 1, "arguments:")
        for i, v in enumerate(argv[1:], 1):
            print(i, ":", v)
    else:
        print(len(argv) - 1, "arguments.")
