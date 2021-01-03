N = int(input())
arr = [True] * (N+1)

for i in range(2,N):
	if arr[i] == False:
		continue
	for j in range(i, N, i):
		arr[j] = False
print(arr)