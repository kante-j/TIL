n = int(input())
arr = [0,1,1,2,3,5]
for i in range(6, n+1):
	arr.append(arr[i-1]+arr[i-2])
print(arr[n])