N,M,K = map(int, input().split())
res = 0
for i in range(K+1):
    tempN = N-i
    tempM = M-K+i
    res = max(res, min((tempN//2),tempM))
print(res)