N = int(input())

lst = []
for i in range(N):
    s, P = map(str, input().split(" "))
    lst.append((s, -int(P), i))

lst.sort(key=lambda x: (x[0], x[1]))
for s, p, i in lst:
    print(i + 1)
