N = int(input())
A = list(map(int, input().split(" ")))
B = list(map(int, input().split(" ")))
C = list(map(int, input().split(" ")))

ans = 0
prev = -1
for i in range(N):
    idx = A[i] - 1
    if (A[i] == prev + 1):
        ans += C[idx - 1]
    ans += B[idx]
    prev = A[i]
print(ans)