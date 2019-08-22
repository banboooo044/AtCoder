import sys
N = int(input())
a = list(map(int,input().split(" ")))

dp = [ [0]*N  for _ in range(N) ]

for l in range(N-1,-1,-1):
    for r in range(l,N):
        turn = ((N - r) + l + 1) % 2

        if turn == 0:
            if r > 0 and l < N-1:
                dp[l][r] = max(a[l] + dp[l+1][r],a[r]+dp[l][r-1])
            elif l < N-1:
                dp[l][r] =  a[l] + dp[l+1][r]
            else:
                dp[l][r] =  a[r] + dp[l][r-1]
        else:
            if r > 0 and l < N-1:
                dp[l][r] = min(-a[l] + dp[l+1][r],-a[r]+dp[l][r-1])
            elif l < N-1:
                dp[l][r] = -a[l] + dp[l+1][r]
            else:
                dp[l][r] = -a[r] + dp[l][r-1]
print(dp[0][N-1])