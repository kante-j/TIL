import sys
s = sys.stdin.readline().rstrip('\n')
stack = []
tag = False
tagString = ""
temp = ""
for c in s:
    if c == '<':
        if len(temp):
            temp = temp[::-1]
            stack.append(temp)
            temp = ""

        tag = True
        tagString += '<'
    elif c == '>':
        tag = False
        tagString += '>'
        stack.append(tagString)
        tagString = ""
    else:
        if tag:
            tagString += c
        else:
            if c == ' ':
                temp = temp[::-1]
                stack.append(temp)
                temp = ""
            else:
                temp += c
if len(temp):
    temp = temp[::-1]
    stack.append(temp)
ans = ""
for i in range(len(stack)):
    if stack[i][-1] == '>':
        ans+=stack[i]
    elif i<len(stack)-1 and stack[i+1][0] == '<':
        ans+=stack[i]
    else:
        ans += stack[i] + " "
print(ans)



