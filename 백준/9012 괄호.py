T = int(input())
for _ in range(T):
	s = input()
	stack = []
	res = True
	for c in s:
		if c == ')':
			if len(stack) > 0 and stack[len(stack)-1] == '(':
				stack.pop(len(stack)-1)
			else:
				res = False
				break
		else:
			stack.append(c)
	if len(stack) == 0 and res:
		print("YES")
	else:
		print("NO")


