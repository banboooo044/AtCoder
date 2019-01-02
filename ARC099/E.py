N,M = map(int,input().split(" "))
e = [[] for _ in range(N)]
for i in range(M):
	a,b = map(int,input().split(" "))
	e[a-1].append(b-1)
	e[b-1].append(a-1)

gr = set([i for i in range(N)])
for i in range(N):
	gr = ((set(e[i]) | set([i])) & gr)

used = [0]*N
g = set(e[0]) | set([0])
for i in range(N):
	print(g,(set(e[i])|set([i])))
	if g == (set(e[i])|set([i])):
		used[0] = 1
print(used)