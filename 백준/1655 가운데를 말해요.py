import heapq
from sys import stdin
N = int(stdin.readline())
minh = []
maxh = []
for _ in range(N):
    num = int(stdin.readline())
    if len(minh) == len(maxh):
        heapq.heappush(minh, (-num, num))
    else:
        heapq.heappush(maxh, (num, num))

    if len(maxh) and minh[0][1] > maxh[0][1]:
        maxOfMinHeap = heapq.heappop(minh)[1]
        minOfMaxHeap = heapq.heappop(maxh)[1]
        heapq.heappush(maxh, (maxOfMinHeap, maxOfMinHeap))
        heapq.heappush(minh, (-minOfMaxHeap, minOfMaxHeap))
    print(minh[0][1])