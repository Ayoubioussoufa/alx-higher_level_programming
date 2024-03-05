#!/usr/bin/python3
class Square:
    def __init__(self, size=0):
        self.__dict__ = {}
        if type(size) == int:
            if size < 0:
                raise ValueError("size must be >= 0")
            self._Square__size = size
        else:
            raise TypeError("size must be an integer")
    def area(self):
        return self._Square__size * self._Square__size
    
    @property
    def size(self):
        return self._Square__size
    
    @size.setter
    def size(self, value):
        if type(value) == int:
            if value < 0:
                raise ValueError("size must be >= 0")
            self._Square__size = value
        else:
            raise TypeError("size must be an integer")

    def my_print(self):
        for i in range(self._Square__size):
            for j in range(self._Square__size):
                print("#", end ="")
            print()
        if self._Square__size == 0:
            print()
