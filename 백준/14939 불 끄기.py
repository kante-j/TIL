import copy
def push(x,y,arr):
    if arr[x][y] == '#':
        arr[x][y] = 'O'
    else:
        arr[x][y] = '#'
    if x > 0:
        if arr[x-1][y] == '#':
            arr[x-1][y] = 'O'
        else:
            arr[x-1][y] = '#'
    if y > 0:
        if arr[x][y-1] == '#':
            arr[x][y-1] = 'O'
        else:
            arr[x][y-1] = '#'
    if x < 9:
        if arr[x+1][y] == '#':
            arr[x+1][y] = 'O'
        else:
            arr[x+1][y] = '#'
    if y < 9:
        if arr[x][y+1] == '#':
            arr[x][y+1] = 'O'
        else:
            arr[x][y+1] = '#'
arr = [['#']*10 for _ in range(10)]
res = 10001
for i in range(10):
    s = input()
    for j in range(10):
        arr[i][j] = s[j]
for i in range(1024):
    arr2 = copy.deepcopy(arr)
    cnt = 0
    for j in range(10):
        if (i & (1<<j)):
            cnt += 1
            push(0,j,arr2)
    for j in range(9):
        for k in range(10):
            if arr2[j][k] == 'O':
                push(j+1, k,arr2)
                cnt += 1
    check = True
    for j in range(10):
        if arr2[9][j] == 'O':
            check = False
            break
    if check:
        res = min(res,cnt)
if res == 10001:
    print(-1)
else:
    print(res)
