N = int(input())
inputs = map(int, input().split())
sosu = []
for i in inputs:
	sosu.append(i)
arr = [True] * (1001)
arr[0] = arr[1] = False
for i in range(2,1001):
	if arr[i] == False:
		continue
	for j in range(i+i, 1001, i):
		arr[j] = False
res = 0
for i in sosu:
	if arr[i] == True:
		res += 1
print(res)