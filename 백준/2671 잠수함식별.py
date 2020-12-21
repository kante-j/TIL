import re
s = input()
res = re.fullmatch(r'(100+1+|01)+', s)
if res == None:
	print("NOISE")
else:
	if res.group() == s:
		print("SUBMARINE")
	else:
		print("NOISE")