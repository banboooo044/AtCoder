M, D = map(int, input().split(" "))
cnt = 0
for m in range(1, M + 1):
    for d in range(10, D + 1):
        ds = str(d)
        d1, d10 = int(ds[1]), int(ds[0])
        if d1 * d10 == m and d1 >= 2 and d10 >= 2:
            cnt += 1

print(cnt)