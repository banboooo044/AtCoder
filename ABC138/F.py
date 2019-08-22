N = 100
cnt = []
p = [1, 2, 4, 8, 16, 32, 64, 128]
tmp = 0
for i in range(1, N):
    for j in range(i, N):
        if (j % i) == (i ^ j):
            tmp += 1
            if i == j and (j + 1) in p:
                cnt.append(tmp)
                tmp = 0

print(cnt)