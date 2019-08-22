N = int(input())
ans = 0
for i in range(1, N):
    if (N - i) // i + 1 <= i:
        break
    if (N - i) % i == 0:
        if (N - i) // i <= i:
            break
        ans += ((N - i) // i)

print(ans)