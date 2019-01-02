#Lotus Leaves

class ford_fulkerson():
	def __init__(self,n):
		# 頂点の値が 0 から始まらない時、used[vertex-1]で目標にアクセス
		self.vertex = []
		self.gragh = [dict() for _ in range(n)]
		self.used = [0] * n
		self.n = n
		self.INF = float('inf')

	def define_vetex(self,ver_index):
		self.vertex.append(ver_index)

	def addEdge(self):
		for i in range(H):
			for j in range(i,W):
		self.gragh[start][end] = 1
		self.gragh[end][start] = 1

	def dfs_shed(self,nowNode,goal,amount):
		if nextNode == goal:
			return amount

		for node,cap in self.gragh[nowNode].items():
			used[node] = 1

			if self.used[node] == 0 and cap > 0:
				tmp_amount = self.dfs_shed(node,goal,min([cap,amount]))

				if tmp_amount > 0:
					self.gragh[nowNode][node] -= tmp_amount	#順方向のcapacity減
					return tmp_amount

	def getMaxFlow(start,goal):
		"""最大流を返すメソッド"""
		flow = 0
		while True:
			self.used = [0] * n
			tmp_flow = self.dfs_shed(start,goal,self.INF)

			if tmp_flow == 0:
				break
			else:
				flow += tmp_flow

		return flow


if __name__ == "__main__":
	H,W = map(int,input().split(" "))
	flow = ford_fulkerson(H*W)

	for i in range(H):
		a = input()
		for j in range(W):
			if a[j] == ".":
				pass
			elif a[j] == "o":
				flow.define_vetex(i*H+j)

			if a[j] == "S":
				start = i * H + j

			elif a[j] == "T":
				end = i * H + j

	for i in range(H):
		for j in range(W):
			if tmp[i][j]:
				flow.addEdge(i)



