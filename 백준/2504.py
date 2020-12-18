# 2504 - 괄호의 값
import sys
s = sys.stdin.readline()
stack = []
result = 0

for c in s:
    if len(stack):
        if c == '(' and stack[-1] == ')':
            stack.pop()
            

