import sys
n = int(input())
arr =[]
for _ in range(n):
	x,y = map(int, sys.stdin.readline().split())
	arr.append((x,y))
arr.sort()
for i in range(n):
	print(arr[i][0], arr[i][1])