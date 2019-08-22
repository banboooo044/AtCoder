N = int(input())
C = [0] * N
mod = 10 ** 9 + 7
dic = [ [ ] for _ in range(2*(10**5)+1)]
for i in range(N):
    C[i] = int(input())
    if i > 0 and C[i] == C[i-1]:
        continue
    dic[C[i]].append(i)

dp = [0] * N
dp[0] = 1
for i in range(1,N):
    dp[i] = dp[i-1] % mod
    if C[i] == C[i-1]:
        continue
    for prev in dic[C[i]]:
        if prev < i:
            if prev > 0:
                dp[i] += dp[prev-1]
            else:
                dp[i] += 1
        dp[i] %= mod

print(dp)
print(dp[N-1] % mod)
