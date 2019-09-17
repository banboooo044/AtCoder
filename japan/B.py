N, K = map(int, input().split(" "))
A = list(map(int, input().split(" ")))

a = 0
b = 0
for i in range(N):
    for j in range(i + 1, N):
        if A[i] > A[j]:
            a += 1

A.extend(A)

for i in range(N):
    for j in range(N, 2 * N):
        if A[i] > A[j]:
            b += 1

print(((K * (K - 1) // 2) * b + K * a) % (10**9 + 7))
