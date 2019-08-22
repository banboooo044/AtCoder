N , K = map(int,input().split(" "))
a = list(map(int,input().split(" ")))

mod = 10 ** 9 + 7

dp = [ [0]*(K+1) for _ in range(N) ]
acc = [ [0]*(K+1) for _ in range(N) ]
mn = min(K,a[0])

for i in range(K+1):
    if i <= mn:
        dp[0][i] = 1
    acc[0][i] = (acc[0][i-1] + dp[0][i])%mod if i > 0 else dp[0][i]%mod

for i in range(1,N):
    dp[i][0] = dp[i-1][0]
    acc[i][0] = dp[i][0]
    for k in range(1,K+1):
        if k - a[i] <= 0:
            dp[i][k] = acc[i-1][k]  % mod 
        else:
            dp[i][k] = (acc[i-1][k] - acc[i-1][k-a[i]-1]) % mod
        acc[i][k] = (acc[i][k-1] + dp[i][k])%mod

print(dp[N-1][K]%mod)