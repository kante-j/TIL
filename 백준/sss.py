visit = [False] * 100001
arr = []
res = []

def dfs(n, cnt):
	if n == len(arr) - 1:
		res.append(cnt)
		return
	temp = arr[n]
	if n + temp < 100001 and n - temp >= 0 and visit[n + temp] == True and visit[n - temp] == True:
		return
	if n + temp < 100001 and visit[n + temp] == False:
		visit[n + temp] = True
		dfs(n + temp, cnt + 1)
		visit[n + temp] = False
	if n - temp >= 0 and visit[n - temp] == False:
		visit[n - temp] = True
		dfs(n - temp, cnt + 1)
		visit[n - temp] = False


def solution(nums):
	global arr
	arr = nums
	dfs(0, 0)
	res.sort()
	if len(res) == 0:
		answer = -1
	else:
		answer = res[0]
	return answer
