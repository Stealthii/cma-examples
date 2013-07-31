#!/usr/bin/env python

"""The Animal classes from test4 rewritten in Python.

Protected attributes in Python are prefixed with an underscore, and private
attributes are prefixed with two. See this page for more information:
http://stackoverflow.com/questions/797771/python-protected-attributes

Functions in Python are always virtual. See this page for more information:
http://stackoverflow.com/questions/4714136/python-how-to-implement-virtual-methods
"""


class Animal:
    _name = ""
    _owners_name = ""
    _breed = ""
    _weight = 0

    def __init__(self, a_name, a_o_name, a_breed, a_weight):
        self._name = a_name
        self._owners_name = a_o_name
        self._breed = a_breed
        self._weight = int(a_weight)

    def __str__(self):
        return "%s the %s says %s" % (self.getName(), self.getBreed(), self.Speak())

    def getBreed(self):
        return str(self._breed)

    def getName(self):
        return str(self._name)

    def Speak(self):
        pass


class Dog(Animal):
    _speak_string = ""

    def __init__(self, a_name, a_o_name, a_breed, a_weight):
        Animal.__init__(self, a_name, a_o_name, a_breed, a_weight)
        self._speak_string = "woof"

    def Speak(self):
        return str(self._speak_string)


class Cat(Animal):
    _speak_string = ""

    def __init__(self, a_name, a_o_name, a_breed, a_weight):
        Animal.__init__(self, a_name, a_o_name, a_breed, a_weight)
        self._speak_string = "Meow!"

    def Speak(self):
        return str(self._speak_string)
