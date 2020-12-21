from sys import stdin
dx = [1,1,0,-1,-1,-1,0,1]
dy = [0,1,1,1,0,-1,-1,-1]
island = [[0] * 51 for _ in range(51)]
visit = [[0] * 51 for _ in range(51)]

global w, h
def reset(arr):
	for i in range(0, 50):
		for j in range(0, 50):
			arr[i][j] = 0

def bfs(x,y):
	q = [(x,y)]
	visit[x][y] = True
	while q:
		front = q.pop(0)
		for i in range(0,8):
			xx = dx[i] + front[0]
			yy = dy[i] + front[1]
			if xx>=0 and xx<h and yy>=0 and yy<w and visit[xx][yy] == False and island[xx][yy] == 1:
				q.append((xx,yy))
				visit[xx][yy] = True

while True:
	w, h = map(int , stdin.readline().split())
	if w == 0 and h == 0:
		break
	for i in range(0, h):
		nums = list(map(int , stdin.readline().split()))
		for j in range(len(nums)):
			island[i][j] = nums[j]
	cnt = 0
	for i in range(0, h):
		for j in range(0, w):
			if island[i][j] == 1 and visit[i][j] == False:
				bfs(i,j)
				cnt += 1
	print(cnt)
	reset(island)
	reset(visit)




