import sys
sys.setrecursionlimit(200004)
N, Q = map(int, input().split(" "))
cnt = [0] * N
edge = [[] for _ in range(N)]
for i in range(N - 1):
    a, b = map(int, input().split(" "))
    edge[a - 1].append(b - 1)
    edge[b - 1].append(a - 1)

for q in range(Q):
    p, x = map(int, input().split(" "))
    cnt[p - 1] += x


def dfs(n, prev, cnt):
    for e in edge[n]:
        if e == prev:
            continue
        cnt[e] += cnt[n]
        dfs(e, n, cnt)


dfs(0, -1, cnt)
print(*cnt)
