import itertools
from sys import stdin
L,C = map(int, input().split())
li = list(map(stdin.readline().split()))
arr = []
for i in li:
    arr.append(i)
arr.sort()

def backtracking(n, m):
    if n==m:
        print()
        return
    for