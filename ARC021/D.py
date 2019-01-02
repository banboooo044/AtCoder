#実行時間的に無理
import heapq

seed = int(input())
INF = float('inf')

def read_data():
	cost = [dict() for _ in range(V)]		#各辺のコストの情報
	mincost = [[INF,i] for i in range(V)]	#集合Xからの最小コスト。集合Xに頂点を追加するたびに更新する。
	mincost[0][0] = 0
	used = [False] * V						#集合Xにすでに追加したかどうかをあらわす。

	for i in range(E):
		a,b,c = map(int,input().split(" "))
		cost[a][b] = c
		cost[b][a] = c

	return V,cost,mincost,used

def prim(V,cost,mincost,used):
	ans = 0
	path = []
	
	while True:
		v = -1
		for i in range(V):
			if (not used[i]) and ((v == -1) or (mincost[i][0] < mincost[v][0])):
				v = i

		if v == -1:
			break

		used[v] = True
		ans += mincost[v][0]
		path.append((mincost[v][1],v))

		for ne,wei in cost[v].items():
			if mincost[ne][0] > wei:
				mincost[ne][0] = wei
				mincost[ne][1] = v

	path.pop(0)

	return ans,path


def generateRandam(seed):
	x = 123456789
	y = 362436069
	z = 521288629

	for i in range(1,5001):
		for j in range(1,201):
			t = x ^ (x << 11)
			x = y
			y = z
			z = seed
			seed = (seed^(seed >> 19)) ^ (t ^ (t >> 8))

			v = seed % 100000 - 50000

			if v >= 0:
				v += 1

			cost[]


ge
param = read_data()
ans , path = prim(*param)

#最小全域木の最小コスト和
print(ans)

#最小全域木の辺
print(path)

