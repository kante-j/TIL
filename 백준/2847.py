N = int(input())
arr = []
for i in range(N):
    arr.append(int(input()))
arr.reverse()
result = 0
for i in range(0, N-1):
    if arr[i] <= arr[i+1]:
        result += arr[i+1]-arr[i]+1
        arr[i+1] = arr[i]-1
print(result)