class UnionFind():
    def __init__(self, n):
        self.table = [i for i in range(n)]
        self.rank = [1 for _ in range(n)]

    def unite(self, x, y):
        # x,yの根を格納する 
        x = self.find(x)
        y = self.find(y)

        #同一グラフ内だった場合
        if x == y:
            return False

        if self.rank[x] > self.rank[y]:
            self.table[y] = x
        else:
            self.table[x] = y
            if self.rank[x] == self.rank[y]:
                self.rank[y] += 1


    def find(self, x):
        """ xの根の値を返すメソッド """
        #xが根である時
        if self.table[x] == x:
            return x
        #xが根でない ==> 根へたどる&根へつけかえる
        self.table[x] = self.find(self.table[x])
        #根の値を返す
        return self.table[x]

    def SameGragh(self,x,y):
        """二つの値が同一グラフ内だった場合:True,違う場合:False"""
        if self.find(x) == self.find(y):
            return True
        else:
            return False

def dfs(i,goal,dis,used):
	used[i] = 1
	if goal == i:
		return dis

	num = -float('inf')

	for next_ver,d in E[i].items():
		if used[next_ver] == 0:
			num = max(dfs(next_ver,goal,dis+d,used),num)

	return num

N,M = map(int,input().split(" "))
tree = UnionFind(N+1)
E = [dict() for _ in range(N+1)]

for i in range(M):
    l,r,d = map(int,input().split(" "))
    if tree.SameGragh(l,r):
    	if d != dfs(l,r,0,[0]*(N+1)):
    		print("No")
    		exit(0)
    else:
    	E[l][r] = d
    	E[r][l] = -d
    	tree.unite(l,r)

print("Yes")





