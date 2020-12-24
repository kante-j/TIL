s = input()
res = []
for i in range(len(s)):
    res.append(s[i:len(s)])
res.sort()
for i in res:
    print(i)