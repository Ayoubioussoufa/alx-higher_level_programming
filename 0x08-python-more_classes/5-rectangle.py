#!/usr/bin/python3
class Rectangle:
    def __init__(self, width=0, height=0):
        self._width = width
        self._height = height
    
    @property
    def width(self):
        return self._width
    
    @width.setter
    def width(self, value):
        if type(value) != int:
            raise TypeError("width must be an integer")
        elif value < 0:
            raise ValueError("width must be >= 0")
        self._width = value
    
    @property
    def height(self):
        return self._height
    
    @height.setter
    def height(self, value):
        if type(value) != int:
            raise TypeError("height must be an integer")
        elif value < 0:
            raise ValueError("height must be >= 0")
        self._height = value
    
    def area(self):
        return self._height * self._width
    
    def perimeter(self):
        if self._height == 0 or self._width == 0:
            return 0
        return self._height * 2 + self._width * 2
    
    def print(self):
        if self._height == 0 or self._width == 0:
            return ""
        for i in range(self._height):
            print("#" * self._width)

    def __str__(self):
        if self._height == 0 or self._width == 0:
            return ""
        for i in range(self._height):
            print("#" * self._width)
        return ""
    
    def __repr__(self):
        rect = "Rectangle(" + str(self._width)
        rect += ", " + str(self._height) + ")"
        return (rect)
    
    def __del__(self):
        print("Bye rectangle...")