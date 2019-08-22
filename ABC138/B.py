N = int(input())
A = list(map(int, input().split(" ")))
s = 0.0
for i in range(N):
    s += 1 / A[i]

ans = 1 / s
print(round(ans, 10))
