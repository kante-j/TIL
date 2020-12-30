def com(x,y):
	res = 1
	for i in range(x-y+1, x+1):
		res *= i
	for j in range(1, y+1):
		res = res // j
	return res

T = int(input())
for i in range(T):
	m,n = map(int, input().split())
	print(int(com(n,m)))