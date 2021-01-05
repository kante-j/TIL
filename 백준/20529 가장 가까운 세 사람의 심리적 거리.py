import itertools
T = int(input())

def cal(a,b):
	res = 0
	for i in range(4):
		if a[i] != b[i]:
			res += 1
	return res

for _ in range(T):
	N = int(input())
	inp = map(str, input().split())
	arr = []
	for i in inp:
		arr.append(i)
	res = 999999999
	temp = 0
	for i in itertools.combinations(arr, 3):
		temp += cal(i[0], i[1])
		temp += cal(i[1], i[2])
		temp += cal(i[0], i[2])
		res = min(res, temp)
		if res == 0:
			break
		temp =0
	print(res)



