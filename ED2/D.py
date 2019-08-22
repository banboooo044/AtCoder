N, W = map(int,input().split(" "))
w,v = [0]*(N+1),[0]*(N+1)
for i in range(N):
    w[i+1],v[i+1] = map(int,input().split(" "))

dp = [ [0]*(W+1) for _ in range(N+1) ]
for i in range(1,N+1):
    for j in range(1,W+1):
        if j >= w[i]:
            dp[i][j] = max([dp[i][j],dp[i-1][j],dp[i-1][j-w[i]] + v[i]])
        else:
            dp[i][j] = max([dp[i][j],dp[i-1][j]])

print(dp[N][W])
