M, N, K = map(int, input().split())
arr = [[0]*101 for _ in range(101)]
visit = [[0]*101 for _ in range(101)]
dx = [-1,1,0,0]
dy = [0,0,-1,1]
for _ in range(K):
	x1,y1,x2,y2 = map(int, input().split())
	for i in range(y1, y2):
		for j in range(x1, x2):
			arr[i][j] = 1
			visit[i][j] = True
res = []
def bfs(x,y):
	cnt = 1
	q = [(x,y)]
	visit[x][y] = True
	while q:
		front = q.pop(0)
		for i in range(4):
			xx = dx[i] + front[0]
			yy = dy[i] + front[1]
			if xx>=0 and xx<M and yy>=0 and yy<N and visit[xx][yy] == False and arr[xx][yy] == 0:
				visit[xx][yy] = True
				q.append((xx,yy))
				cnt += 1
	res.append(cnt)
count = 0
for i in range(M):
	for j in range(N):
		if arr[i][j] == 0 and visit[i][j] == False:
			bfs(i,j)
			count +=1
res.sort()
print(count)
for i in res:
	print(i, end=" ")