N,M = map(int,input().split(" "))
ab = []
for i in range(N):
    a,b = map(int,input().split(" "))
    ab.append((a,b))

ab.sort()
ans = 0
for i in range(N):
    if M <= ab[i][1]:
        ans += (M * ab[i][0])
        break
    else:
        ans += (ab[i][0] * ab[i][1])
        M -= ab[i][1]

print(ans)


