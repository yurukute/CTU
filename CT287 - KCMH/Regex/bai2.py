import re

fname = input()
with open(fname) as file:
    data = file.read()
    data = re.sub(r'^ +', '', data)     # remove spaces at file's beginning
    data = re.sub(r'\n +', '\n', data)  # remove spaces before paragraphs
    data = re.sub(r' +', ' ', data)     # remove spaces inside paragraphs
    print(data)
