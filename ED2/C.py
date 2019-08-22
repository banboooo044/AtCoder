N = int(input())
a,b,c = [0]*N,[0]*N,[0]*N
for i in range(N):
    a[i],b[i],c[i] = map(int,input().split(" "))

dp = [ [0,0,0] for _ in range(N) ]
dp[0][0] = a[0]
dp[0][1] = b[0]
dp[0][2] = c[0]

for i in range(1,N):
    dp[i][0] = max(dp[i-1][1],dp[i-1][2])+a[i]
    dp[i][1] = max(dp[i-1][0],dp[i-1][2])+b[i]
    dp[i][2] = max(dp[i-1][0],dp[i-1][1])+c[i]

print(max(dp[-1]))
        

