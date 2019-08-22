N,M = map(int,input().split(" "))
A,B = [0]*(N-1+M),[0]*(N-1+M)
edge = [ [] for _ in range(N) ]
par = [(-1,0)] * N
root = [0] * N
for i in range(N-1+M):
    A[i],B[i] = map(int,input().split(" "))
    edge[A[i]-1].append(B[i]-1)
    root[B[i]-1] = 1

que = []
for i in range(N):
    if root[i] == 0:
        par[i] = (0,0)
        que.append((i+1,0,0))
        break

while len(que) > 0:
    cur = que.pop()
    pos,prev,depth = cur
    for nx in edge[pos-1]:
        if par[nx][0] < depth+1:
            par[nx] = (depth+1,pos)
            que.append((nx+1,pos,depth+1))

for val,e in par:
    print(e)
