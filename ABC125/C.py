from itertools import accumulate
N = int(input())
A = list(map(int,input().split(" ")))
def gcd (a: int,b: int) -> int:
    if a < b: a,b = b,a
    return a if b == 0 else gcd(b,a%b)

gcdForward = list(accumulate(A,gcd))
gcdBackward = list(accumulate(A[::-1],gcd))
gcdBackward.reverse()
if N == 2:
    print(max(A))
    exit(0)
else:
    ans = max(gcdBackward[1],gcdForward[N-2])
    for i in range(1,N-1):
        ans = max(ans,gcd(gcdForward[i-1],gcdBackward[i+1]))
    print(ans)