N,M = map(int,input().split(" "))
inedge = [0] * N
edge = [ [] for _ in range(N) ]
for i in range(M):
    x,y = map(int,input().split(" "))
    inedge[y-1] += 1
    edge[x-1].append(y-1)

stack = []
for i in range(N):
    if inedge[i] == 0:
        stack.append((i,0))

ans = [0] * N
while len(stack) != 0:
    nextVer,passLen = stack.pop()
    for e in edge[nextVer]:
        inedge[e] -= 1
        ans[e] = max(ans[e],passLen+1)
        if inedge[e] == 0:
            stack.append((e,ans[e]))

print(max(ans))