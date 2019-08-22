from itertools import product
N, M = map(int, input().split(" "))
s = []
for i in range(M):
    s.append(list(map(int, input().split(" ")))[1:])

p = list(map(int, input().split(" ")))
ans = 0
for tup in product(range(2), repeat=N):
    for i in range(M):
        flg = True
        cnt = 0
        for d in s[i]:
            cnt += tup[d - 1]
        if cnt % 2 != p[i]:
            flg = False
            break

    if flg:
        ans += 1

print(ans)