#!/usr/bin/env python

import sys
from animals import Cat, Dog

animal_lines = []

try:
    for line in open("animals.dat","r").readlines():
        animal_lines.append(line.strip("\n").split())
except IOError:
    print "ERROR: Unable to open file!"
    sys.exit(1)

for element in animal_lines:
    if element[0] == "Cat":
        print Cat(element[1], element[2] + element[3], element[4], element[5])
    elif element[0] == "Dog":
        print Dog(element[1], element[2] + element[3], element[4], element[5])
