from sys import stdin
n, m, v = map(int, stdin.readline().split())

mpas = [[0]*(n+1) for i in range(n+1)]
visitbfs = [0] * (n+1)
visitdfs = [0] * (n+1)

for _ in range(m):
	x = list(map(int, stdin.readline().split()))
	mpas[x[0]][x[1]] = 1
	mpas[x[1]][x[0]] = 1



def bfs(s):
	q = []
	q.append(s)
	visitbfs[s] = 1
	while len(q):
		first = q.pop(0)
		print(first, end=" ")
		for i in range(1, n+1):
			if mpas[first][i] == 1 and visitbfs[i] ==0:
				q.append(i)
				visitbfs[i] = 1



def dfs(s):
	print(str(s),end=" ")
	visitdfs[s] = 1
	for i in range(1,n+1):
		if mpas[s][i] == 1 and visitdfs[i]==0:
			dfs(i)
	return

dfs(v)
print()
bfs(v)