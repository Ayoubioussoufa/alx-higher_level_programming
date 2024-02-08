#!/usr/bin/python3
for num in range(122, 96, -1):
    if num % 2:
        print(chr(num - 32), end="")
    else:
        print(chr(num), end="")
