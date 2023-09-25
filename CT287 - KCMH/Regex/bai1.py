import re

fname = input()
with open(fname) as file:
    for match in re.findall(r'ISBN \d{1,5}-\d{3}-\d{5}-\d', file.read()):
        print(match)
