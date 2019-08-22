N,K = map(int,input().split(" "))
h = list(map(int,input().split(" ")))

dp = [float('inf')] * N
dp[0] = 0
dp[1] = dp[0] + abs(h[1]-h[0])

for i in range(2,N):
    for j in range(1,min(K+1,i+1)):
        dp[i] = min(dp[i],dp[i-j]+abs(h[i]-h[i-j]))

print(dp[N-1])