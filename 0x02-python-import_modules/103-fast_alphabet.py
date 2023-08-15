#!/usr/bin/python3
import string
from functools import reduce

reduce(lambda x, _: print(string.ascii_uppercase, end='\n'), range(1))
