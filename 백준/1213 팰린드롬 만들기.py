s= input()
arr = [0]*27
for i in s:
    num = ord(i)-ord('A')
    arr[num] += 1
res = ""
for i in arr:
    if i % 2 != 0:
        res = "I'm Sorry Hansoo"
if len(res):
    print(res)
else:
    for i in range(len(arr)):
        res += (chr(i+ord('A')))*(arr[i]//2)
    print(res + res[::-1])