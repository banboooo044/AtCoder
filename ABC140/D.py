N, K = map(int, input().split(" "))
S = input()

cnt = []
tmp = 1
for i in range(N - 1):
    if S[i] != S[i + 1]:
        cnt.append(tmp)
        tmp = 1
    else:
        tmp += 1

cnt.append(tmp)
bn = 1 + 2 * K
if len(cnt) <= bn:
    print(N - 1)
    exit(0)
ans = sum(cnt) - (len(cnt) - bn + 1)
print(ans)