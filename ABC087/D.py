
class UnionFind():
    def __init__(self, n):
        self.table = [i for i in range(n)]
        self.rank = [1 for _ in range(n)]
        Nself.pos =  

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

N,M = map(int,input().split(" "))
tree = UnionFind(N)
array = {}
l,r,d = map(int,input().split(" "))
tree.unite(l,r)
array[l] = 0
array[r] = d
for i in range(M-1):
    l,r,d = map(int,input().split(" "))
    if tree.SameGragh(l,r):
        if array[l] + d != array[r] :
            print("No")
    else:
        if l in array:
            array[l]



