H,W = map(int,input().split(" "))
a = [ ]
for i in range(H):
    ai = input()
    a.append(ai)

md = int(1e9 + 7)
dp = [ [0]*W for _ in range(H) ]
dp[0][0] = 1
for h in range(H):
    for w in range(W):
        if a[h][w] == '.':
            if w > 0:
                dp[h][w] += dp[h][w-1]
            if h > 0:
                dp[h][w] += dp[h-1][w]
        dp[h][w] %= md

print(dp[H-1][W-1])