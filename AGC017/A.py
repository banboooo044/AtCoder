N,P = map(int,input().split(" "))
A = list(map(int,input().split(" ")))

odd = 0
even = 0
for i in range(N):
    if A[i] % 2 == 1:
        odd += 1
    else:
        even += 1

def nCr(n:int ,r: int) -> int:
    r,v = min(n-r,r),1
    for i in range(r):
        v = (v * (n-i) // (i+1))
    return v

ans = 0
for j in range(1,N+1,2):
    if j > odd:
        break
    ans += nCr(odd,j) * (2**even)

if P == 1:
    print(ans)
else:
    print(2**N - ans)