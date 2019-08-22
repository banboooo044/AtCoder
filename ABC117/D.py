N, K = map(int,input().split(" "))
A = list(map(int,input().split(" ")))
A_ = [0] * N

k = K
K_dig = -1
while k > 0:
    k >>= 1
    K_dig += 1

border = ((1 << (K_dig+1)) - 1)
for i in range(N):
    if A[i] > border:
        a = A[i]
        j = (K_dig + 1)
        while a > border:
            if (a >> j) & 1:
                a -= (1 << j)
            j += 1
        A_[i] = a
    else:
        A_[i] = A[i]


def dfs(dig,curValue):
    if dig == -1:
        return curValue
    if (curValue + (1 << dig)) > K:
        return dfs(dig-1,curValue)

    oneCount = 0
    for i in range(N):
        if (A_[i] >> dig) & 1:
            oneCount += 1
    if oneCount <= (N-oneCount):
        return dfs(dig-1,curValue + (1 << dig))
    else:
        return dfs(dig-1,curValue)
    
val = dfs(K_dig,0)

ans = 0
for a in A:
    ans += (val ^ a)
print(ans)
