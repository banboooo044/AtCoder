N = int(input())
W = [ [] for _ in range(N) ]
dist = [-1] * N
dist[0] = 0

for i in range(N-1):
    u,v,w = map(int,input().split(" "))
    W[u-1].append(( v-1, w))
    W[v-1].append((u-1, w))

lst = [ ( 0 ,0, -1)]
idx = 0
while len(lst) > idx:
    cur, d, prev = lst[idx]
    idx += 1
    for v, w in W[cur]:
        if v == prev:
            continue
        dist[v] = d + w
        lst.append( (v, dist[v], cur))

for ans in dist:
    print(ans % 2)