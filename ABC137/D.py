import heapq as hp
N, M = map(int, input().split(" "))
AB = []
for i in range(N):
    a, b = map(int, input().split(" "))
    AB.append((a, b))

AB.sort(key=lambda x: (-x[0], -x[1]))
j = 0
ans = 0
que = []
for i, (a, b) in enumerate(AB):
    if j + a <= M:
        hp.heappush(que, b)
        j += 1
        ans += b
    else:
        if len(que) > 0 and que[0] < b:
            v = hp.heappushpop(que, b)
            ans -= v
            ans += b

print(ans)