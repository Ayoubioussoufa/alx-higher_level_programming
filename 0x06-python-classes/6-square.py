#!/usr/bin/python3
class Square:
    def __init__(self, size=0, position=(0, 0)):
        self.__dict__ = {}
        self._Square__size = size
        self.__position = position
    
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
        if self._Square__size == 0:
            print()
            return
        [print("") for i in range(0, self.__position[1])]
        for j in range(self._Square__size):
            print(" " * self.__position[0], end="")
            print("#" * self._Square__size)

    @property
    def position(self):
        return self.__position
    
    @position.setter
    def position(self, value):
        if not isinstance(value, tuple) or len(value) != 2 or not all(isinstance(x, int) and x > 0 for x in value):
            raise TypeError("position must be a tuple of 2 positive integers")
        self.__position = value