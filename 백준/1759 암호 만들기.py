import itertools
from sys import stdin
L,C = map(int, input().split())
li = list((stdin.readline().split()))
arr = []
for i in li:
    arr.append(i)
arr.sort()
mo = ['a','e','i','o','u']
for i in list(itertools.combinations(arr,L)):
    res = ""
    for j in i:
        res += j
    for m in mo:
        if m in res:
            cnt = 0
            for c in res:
                if c not in mo:
                    cnt += 1
            if cnt >= 2:
                print(res)
                break
