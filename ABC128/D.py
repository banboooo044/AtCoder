N, K = map(int, input().split(" "))
V = list(map(int, input().split(" ")))
V_rev = list(reversed(V))
val = [[0] * (N + 1) for _ in range(N + 1)]

for i in range(N):
    for j in range(N):
        val[i + 1][j] = val[i][j] + V[i]
        val[i][j + 1] = val[i][j] + V_rev[j]

val[N][N] = val[N][N - 1] + V_rev[N - 1]

ans = 0
for l in range(N + 1):
    for r in range(N + 1):
        num = l + r
        if num > K or num > N:
            continue
        rm = []
        can = (K - num)
        for li in range(l):
            if V[li] < 0:
                rm.append(V[li])
        for ri in range(r):
            if V_rev[ri] < 0:
                rm.append(V_rev[ri])

        rm.sort()
        ans = max(ans, val[l][r] - sum(rm[:can]))

print(ans)