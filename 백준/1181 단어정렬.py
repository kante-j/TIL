num = int(input())
arr = set()
for i in range(num):
	s = input()
	arr.add(s)

arr = list(arr)
arr.sort()
arr.sort(key=lambda x : len(x))
for s in arr:
	print(s)