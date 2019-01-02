class UnionFind():
    def __init__(self, n):
        self.table = [i for i in range(n)]
        self.vertex = [[-1] * n for _ in range(n)]
        self.rank = [1 for _ in range(n)]

    def unite(self, x, y, num):
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

        self.vertex[x][y] = num
        self.vertex[y][x] = num

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

    def ansQuerry(self,x,y):
        if self.vertex[x][y] != -1:
            return self.vertex[x][y]
        else:
            if self.table[x] == x and self.table[y] == y:
                return -1
            else:
                return self.ansQuerry(self.find(x),self.find(y)) 

if __name__ == "__main__":
    N,M = map(int,input().split(" "))
    tree = UnionFind(N)

    for i in range(M):
        a,b = map(int,input().split(" "))
        tree.unite(a-1,b-1,i+1)

    Q = int(input())
    ans = []

    for i in range(Q):
        x,y = map(int,input().split(" "))
        ans.append(tree.ansQuerry(x-1,y-1))

    for i in ans:
        print(i)





