N = int(input())
P = list(map(int, input().split(" ")))

s = 0
for i in range(N - 1):
    for j in range(i + 1, N):
        s += sorted(P[i:j + 1])[-2]
        print(sorted(P[i:j + 1])[-2], end=" ")
    print()

print(s)