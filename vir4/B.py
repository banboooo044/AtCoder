K, S = map(int,input().split(" "))
ans = 0
for X in range(K+1):
    for Y in range(K+1):
        if 0 <= (S - X - Y) <= K:
            ans += 1

print(ans)