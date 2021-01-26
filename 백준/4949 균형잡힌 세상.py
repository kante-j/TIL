while(True):
    s = input()
    if len(s)==1 and s==".":
        break
    stack = []
    temp = True
    for c in s:
        if c == '(':
            stack.append('(')
        elif c == '[':
            stack.append('[')
        elif c==')':
            if len(stack)>0 and stack[len(stack)-1] == '(':
                stack.pop()
            elif not stack or stack[len(stack)-1]=='[':
                temp=False
                break
        elif c==']':
            if  len(stack)>0 and stack[len(stack)-1] == '[':
                stack.pop()
            elif not stack or stack[len(stack)-1]=='(':
                temp=False
                break
    if temp == True and len(stack) == 0:
        print("yes")
    else:
        print("no")