#!/usr/bin/python3
class Rectangle:
    number_of_instances = 0
    print_symbol = "#"
    def __init__(self, width=0, height=0):
        self._width = width
        self._height = height
        Rectangle.number_of_instances += 1
    
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
            print(self.print_symbol * self._width)

    def __str__(self):
        if self._height == 0 or self._width == 0:
            return ""
        for i in range(self._height):
            print(self.print_symbol * self._width)
        return ""
    
    def __repr__(self):
        rect = "Rectangle(" + str(self._width)
        rect += ", " + str(self._height) + ")"
        return (rect)
    
    def __del__(self):
        Rectangle.number_of_instances -= 1
        print("Bye rectangle...")
    
    @staticmethod
    def bigger_or_equal(rect_1, rect_2):
        if not isinstance(rect_1, Rectangle):
            raise TypeError("rect_1 must be an instance of Rectangle")
        elif not isinstance(rect_2, Rectangle):
            raise TypeError("rect_2 must be an instance of Rectangle")
        if rect_1.area() >= rect_2.area():
            return rect_1
        else:
            return rect_2
    
    @classmethod
    def square(cls, size=0):
        return cls(size, size)
