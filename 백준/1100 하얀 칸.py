from sys import stdin
chess = [[0]*8 for _ in range(8)]
for i in range(8):
	s = stdin.readline()
	for j in range(8):
		chess[i][j] = s[j]
cnt = 0
check = True
for i in range(8):
	for j in range(8):
		if check and chess[i][j] == 'F':
			cnt+=1
		check = not check
	check = not check

print(cnt)
