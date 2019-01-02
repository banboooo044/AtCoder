from itertools import combinations

def roundRobin(V,V_emb,edge,edge_king):
	cost = 0
	prev = [0,(0)]
	for tup in combinations(range(1,(V_emb+1)),V):
		for i,j in combinations(range(V),2):
			if edge_king[tup[i]][tup[j]] == 1:
				cost += edge[i+1][j+1]

		if prev[0] < cost:
			prev[0] = cost
			prev[1] = tup
			cost = 0

		if prev[0] == sumW:
			return [cost,tup]

	return prev

#実行部分
V , E = map(int,input().split(" "))
edge = [[0]*(V+1) for _ in range(V+1)]

sumW = 0
for i in range(E):
	u,v,w = map(int,input().split(" "))
	sumW += w
	edge[u][v] = w
	edge[v][u] = w

V_emb,E_emb = map(int,input().split(" "))
edge_king = [[0]*(V_emb+1) for _ in range(V_emb+1)]

for i in range(E_emb):
	a,b = map(int,input().split(" "))
	edge_king[a][b] = 1
	edge_king[b][a] = 1


ans = roundRobin(V,V_emb,edge,edge_king)

for i,j in zip(range(1,(V+1)),ans[1]):
	print(str(i) + " " + str(j))
