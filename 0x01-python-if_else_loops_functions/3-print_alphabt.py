#!/usr/bin/python3
start = 97
end = 122
for ascii in range(start, end + 1):
    if (chr(ascii) == 'q' or chr(ascii) == 'e'):
        continue
    else:
        print(chr(ascii), end='')
