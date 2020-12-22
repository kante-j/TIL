from sys import stdin
K = int(input())
arr = []
for _ in range(K):
	num = int(stdin.readline())
	if num == 0:
		arr.pop(len(arr)-1)
	else:
		arr.append(num)
res = 0
for i in arr:
	res += i
print(res)