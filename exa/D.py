N,X = map(int,input().split(" "))
S = list(map(int,input().split(" ")))

def nCr_all(n):
    nCr = [1] * (n+1)
    for i in range(1,n+1):
        nCr[i] = nCr[i-1] * (n - i + 1) / (i)
    return nCr


value = []
S.sort(reverse=True)
for i in range(N):
    value.append(X)
    value = list(map(lambda x: x%S[i],value))

nCr = nCr_all(N-1)

print(nCr)
ans = 0
for i in range(N):
    ans += value[i] * nCr[i]
print(int(ans))

