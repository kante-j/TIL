# 1157 - 단어 공부
arr = [0]*27
s = input()
for c in s:
    temp = ord(c)
    if ord(c)>=ord('a'):
        temp = ord(c)-ord('a')+ord('A')
    arr[temp-ord('A')] +=1
max = 0
result = 0
for i in range(len(arr)):
    if max < arr[i]:
        max = arr[i]
        result = i
    elif max == arr[i] and max != 0:
        result = '?'
if result == '?':
    print(result)
else:
    print(chr(result+ord('A')))