#!/usr/bin/env python


class Vector():
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def __add__(self, other):
        return (Vector(self.a + other.a, self.b + other.b))

    def __sub__(self, other):
        return (Vector(self.a - other.a, self.b - other.b))

    def __mul__(self, other):
        return (Vector(self.a * other.a, self.b * other.b))

    def __div__(self, other):
        return (Vector(self.a / other.a, self.b / other.b))

    def __str__(self):
        return 'Vector (%d, %d)' % (self.a, self.b)

vector1 = Vector(2, 4)
vector2 = Vector(3, 6)
vector3 = vector1 + vector2
print vector3 - Vector(1,2)
