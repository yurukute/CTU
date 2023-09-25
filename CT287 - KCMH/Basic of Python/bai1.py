s = input()
d = {}
for c in s:
    if c in d:
        d.update({c: d[c]+1})
    else:
        d.update({c: 1})
for x in sorted(d):
    print(x + ":", d[x])
