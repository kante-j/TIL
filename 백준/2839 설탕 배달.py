N = int(input())
arr = [99999]*5001
arr[3] = 1
arr[5] =1

q = [3,5]
while q:
	front = q.pop(0)
	if front+5 > 5000:
		continue
	if arr[front+3] > arr[front]+1:
		arr[front+3] = arr[front]+1
		q.append(front+3)
	if arr[front+5] > arr[front]+1:
		arr[front+5] = arr[front]+1
		q.append(front+5)
if arr[N] == 99999:
	print(-1)
else:
	print(arr[N])


