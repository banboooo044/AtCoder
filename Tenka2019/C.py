N = int(input())
S = list(input())

white = [0] * N
black = [0] * N

for i in range(N):
    if S[i] == '#':
        white[i] += 1
    else:
        black[i] += 1

for i in range(N-1):
    white[i+1] += white[i]
    black[i+1] += black[i]

ans = min(white[N-1],black[N-1])
for i in range(N-1):
    ans = min(ans,white[i]+(black[-1] - black[i]))
print(ans)

