from sys import stdin
t = int(stdin.readline())
while t:
    t -= 1
    n = int(stdin.readline())
    arr = []
    for i in range(n):
        arr.append(stdin.readline().rstrip('\n'))
    check = True
    arr.sort()
    for i in range(0,n-1):
        if arr[i] == arr[i+1][0:len(arr[i])]:
            check = False
            break
    if check == False:
        print("NO")
    else:
        print("YES")
