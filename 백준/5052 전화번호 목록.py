t = int(input())
while t:
    t -= 1
    n = int(input())
    arr = []
    for i in range(n):
        arr.append(input())
    check = True
    for i in range(0,n):
        for j in range(0,n):
            if i == j:
                continue
            else:
                if arr[i] == arr[j][0:len(arr[i])]:
                    check = False
                    break
        if check == False:
            print("NO")
            break
    if check:
        print("YES")
