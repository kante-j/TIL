while True:
	num = input()
	if num == '0':
		break
	check = True
	for i in range(len(num)//2):
		if num[i] != num[len(num)-1-i]:
			check = False
			break
	if check:
		print('yes')
	else:
		print('no')
