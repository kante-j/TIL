s = input()
check = "UCPC"
index = 0
for i in range(len(s)):
	if s[i] == check[index]:
		index += 1
	if index > 3:
		break
if index == 4:
	print("I love UCPC")
else:
	print("I hate UCPC")