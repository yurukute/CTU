s = input()
s = [s[i:i + 3] for i in range(0, len(s), 3)]
if len(s) >= 3 and s[0] == 'ATG' and s[len(s) - 1] in (
        'TAA', 'TAG',
        'TGA') and not [x for x in s[1:len(s) - 1] if len(set(x)) != 3]:
    print('YES')
else:
    print('NO')
