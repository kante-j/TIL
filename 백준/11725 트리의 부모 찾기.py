import sys
sys.setrecursionlimit(10 ** 9)
N = int(input())
graph = [[] for _ in range(N + 1)]
parent = [0 for _ in range(N + 1)]

for i in range(N - 1):
	a, b = map(int, sys.stdin.readline().split())
	graph[a].append(b)
	graph[b].append(a)

def dfs(start, graph, parent):
	for next in graph[start]:
		if parent[next] == 0:
			parent[next] = start
			dfs(next, graph, parent)

parent[1] = 1
dfs(1, graph, parent)
for i in parent[2:]:
	print(i)
