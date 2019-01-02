from itertools import product
K,N = map(int,input().split(" "))
v = [""] * N
V = [0] * N
w = [""] * N
for i in range(N):
	v[i],w[i] = map(str,input().split(" "))
	V[i] = [int(num) for num in v[i]]

for tup in product(range(1,4),repeat=K):
	#print(tup)
	dic = {}
	flg = True
	for j in range(N):
		l = 0
		for num in V[j]:
			if len(w[j]) < (l + tup[num-1]):
				flg = False
				break
			elif num in dic:
				if dic[num] != w[j][l:l+tup[num-1]]:
					flg = False
					break

			else:
				dic[num] = w[j][l:l+tup[num-1]]

			l += tup[num-1]
	#print(dic)

	if flg:
		for i in range(N):
			s = ""
			for n in V[i]:
				s += dic[n]

			if s != w[i]:
				flg = False
				break

	if flg:
		for i in range(1,K+1):
			print(dic[i])
		exit(0)












		










