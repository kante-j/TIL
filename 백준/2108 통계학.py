from sys import stdin
from collections import Counter
N = int(input())
arr = []
hap = 0
dd = []
for _ in range(N):
    num = int(stdin.readline().rstrip('\n'))
    arr.append(num)
    hap += num
    dd.append(num)
    # if num in dd:
    #     dd[num] += 1
    # else:
    #     dd[num] = 1

arr.sort()
print(round(hap/N))
print(arr[N//2])

dd = sorted(dd)
c = Counter(dd).most_common(2)
if len(c) == 1:
    print(c[0][0])
else:
    if c[0][1] == c[1][1]:
        print(c[1][0])
    else:
        print(c[0][0])
print(arr[N-1] - arr[0])
