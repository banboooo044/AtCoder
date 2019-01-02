from time import time
from random import random
from random import randint
from math import sqrt
from math import exp


class Annealing():
	def __init__(self,V,runTime):
		self.startTime = 0
		self.endTime = runTime 
		self.runTime = runTime

		self.startTemp = 100
		self.endTemp = 10

		self.lapse = 0

		self.bestScore = 0
		self.currentScore = 0

		self.edgeG = [[0] * V for _ in range(V)]
		self.edgeGemb = None

		self.bestState = {}	# key:Gの頂点,value:Gembの頂点
		self.currentState_G = {i:INF for i in range(V)}
		self.currentState_Gemb = None

		self.V = V
		self.Vemb = 0

	def get_startTime(self,startTime):
		self.startTime = startTime
		self.endTime += startTime

	def init_Vemb(self,Vemb):
		self.Vemb = Vemb
		self.currentState_Gemb = {i:INF for i in range(Vemb)}
		self.edgeGemb = {i:[] for i in range(Vemb)}

	def add_G_Edge(self,ver1,ver2,weight):
		""" Gの辺の入力を受け取る。"""
		self.edgeG[ver1][ver2] = weight
		self.edgeG[ver2][ver1] = weight

	def add_Gemb_edge(self,ver1,ver2):
		""" Gembの辺の入力を受け取る"""
		self.edgeGemb[ver1].append(ver2)
		self.edgeGemb[ver2].append(ver1)


	def init_vertex_correspond(self,Vemb):
		oneEdge = int(sqrt(Vemb))
		score = 0

		"""初期解を設定"""
		if V <= ((oneEdge - 2) ** 2):
			useArray = [list(range(i*oneEdge+1,(i+1)*oneEdge-1)) for i in range(1,oneEdge-1)]
			useArray = [j for i in useArray for j in i]
			for i ,j in zip(range(V),useArray):
				self.currentState_G[i] = j
				self.currentState_Gemb[j] = i
		else:
			for i in range(V):
				self.currentState_G[i] = i
				self.currentState_Gemb[i] = i

		for verG in range(V):
			for verGemb in self.edgeGemb[self.currentState_G[verG]]:
				if self.currentState_Gemb[verGemb] != INF:
					score += self.edgeG[self.currentState_Gemb[verGemb]][verG]

		self.bestState = self.currentState_G
		return score
	
	def run_annealing(self,initialAns):
		#print("initialAns ==> ",initialAns)

		self.bestScore = initialAns
		self.currentScore = initialAns

		i = 0

		while True:
			a = randint(0,self.V-1)
			b = randint(0,self.Vemb-1)

			changeVer = [a,b]

			nextScore = self.getScore(changeVer)

			self.lapse = time() - self.startTime

			if self.lapse > self.runTime :
				break

			temp = self.startTemp + (self.endTemp - self.startTemp) * self.lapse / self.endTime
			probability = exp((nextScore - self.currentScore) / temp)

			if (nextScore > self.currentScore) or (probability > random()):
				self.currentScore = nextScore
				self.updateState(changeVer)

				if nextScore > self.bestScore:
					self.bestState = self.currentState_G
					self.bestScore = self.currentScore
					#print("ベスト更新!!")
					#print("bestScore ==> " + str(self.bestScore))

		return self.bestState,self.bestScore


	def getScore(self,changeVer):
		""" Gの頂点 changeVer[0]を Gembの頂点 changeVer[1] に移動させる"""
		verG = changeVer[0]
		verGemb = changeVer[1]
		nextScore = self.currentScore
		swap_verG = self.currentState_Gemb[verGemb]

		if self.currentState_Gemb[verGemb] != INF:
			#print("pattern SWAP")
			for Gemb in self.edgeGemb[self.currentState_G[verG]]:
				if self.currentState_Gemb[Gemb] != INF:
					nextScore += ((self.edgeG[self.currentState_Gemb[Gemb]][swap_verG] - self.edgeG[self.currentState_Gemb[Gemb]][verG])*2)
					#print()
					#print(str(self.currentState_G[verG]) + "=>" + str(Gemb))
					#print(self.edgeG[self.currentState_Gemb[Gemb]][swap_verG] - self.edgeG[self.currentState_Gemb[Gemb]][verG])
					#print()

				if self.currentState_Gemb[Gemb] == swap_verG:
					nextScore += (self.edgeG[verG][swap_verG] * 4)

			for Gemb in self.edgeGemb[verGemb]:
				if self.currentState_Gemb[Gemb] != INF:
					nextScore += ((self.edgeG[self.currentState_Gemb[Gemb]][verG] - self.edgeG[self.currentState_Gemb[Gemb]][swap_verG])*2)
					#print()
					#print(str(verGemb) + "=>" + str(Gemb))
					#print((self.edgeG[self.currentState_Gemb[Gemb]][verG] - self.edgeG[self.currentState_Gemb[Gemb]][swap_verG]))
					#print()
			

		else:
			#print("pattern Not SWAP")
			for Gemb in self.edgeGemb[self.currentState_G[verG]]:
				if self.currentState_Gemb[Gemb] != INF:
					nextScore -= (self.edgeG[self.currentState_Gemb[Gemb]][verG]*2)
					#print()
					#print(str(self.currentState_G[verG]) + "=>" + str(Gemb))
					#print(self.edgeG[self.currentState_Gemb[Gemb]][verG])
					#print()


			for Gemb in self.edgeGemb[verGemb]:
				if self.currentState_Gemb[Gemb] != INF:
					nextScore += (self.edgeG[self.currentState_Gemb[Gemb]][verG]*2)
					#print()
					#print(str(verGemb) + "=>" + str(Gemb))
					#print((self.edgeG[self.currentState_Gemb[Gemb]][verG]))
					#print()

		return nextScore
	
	def updateState(self,changeVer):
		verG = changeVer[0]
		verGemb = changeVer[1]
		swap_verG = self.currentState_Gemb[verGemb]

		if swap_verG != INF:
			self.currentState_G[swap_verG] = self.currentState_G[verG]
			self.currentState_Gemb[self.currentState_G[verG]] = swap_verG
			self.currentState_G[verG] = verGemb
			self.currentState_Gemb[verGemb] = verG

		else:
			self.currentState_Gemb[self.currentState_G[verG]] = INF
			self.currentState_G[verG] = verGemb	
			self.currentState_Gemb[verGemb] = verG

	def DEBUG(self):
		print()
		print("currentState")
		print(self.currentState_G)
		print(self.currentState_Gemb)
		print()
		print("currentScore")
		print(self.currentScore)
		print()

	def DEBUG_getScore(self,*param):
		print(*param)



if __name__ == "__main__":
	INF = float('inf')
	runTime = 8.50
	V,E = map(int,input().split(" "))
	An = Annealing(V,runTime)

	for i in range(E):
		u,v,w = map(int,input().split(" "))
		An.add_G_Edge(u-1,v-1,w)

	Vemb,Eemb = map(int,input().split(" "))
	An.init_Vemb(Vemb)
	for i in range(Eemb):
		u,v = map(int,input().split(" "))
		An.add_Gemb_edge(u-1,v-1)

	An.get_startTime(time())

	initialAns = An.init_vertex_correspond(Vemb)
	bestState,bestScore = An.run_annealing(initialAns)

	#print()
	#print("RESULT!!!")
	#print("bestState ==> " + str(bestState))
	#print("bestScore ==> " + str(bestScore))

	for key,value in bestState.items():
		print(str(key+1) + " " + str(value+1))



