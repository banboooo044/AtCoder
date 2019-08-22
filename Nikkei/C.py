N = int(input())
S = [0] *  N
A,B = [0]*N,[0]*N
for i in range(N):
    A[i],B[i] = map(int,input().split(" "))
    S[i] = (A[i]+B[i],i)
S.sort(reverse=True)

ans = 0
for i in range(N):
    if i % 2 == 0:
        ans += A[S[i][1]]
    else:
        ans -= B[S[i][1]]

print(ans)