import sys
sentence = sys.stdin.readline().rstrip('\n')
f = sys.stdin.readline().rstrip('\n')

index = 0
cnt = 0
while index < len(sentence):
    check = True
    for i in range(len(f)):
        if i+index > len(sentence)-1:
            check = False
            break
        if f[i] != sentence[i+index]:
            check = False
            break
    if check:
        cnt += 1
        index += len(f)
    else:
        index += 1
print(cnt)
