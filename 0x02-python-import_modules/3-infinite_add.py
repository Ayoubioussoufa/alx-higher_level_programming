#!/usr/bin/python3
if __name__ == "__main__":
    from sys import argv
    result = 0
    for i in enumerate(argv[1:], 1):
        result += int(i[1])
    print(result)
