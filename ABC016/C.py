N,M = map(int,input().split(" "))
dic = {i:[i] for i in range(1,N+1)}
for i in range(M):
	A,B = map(int,input().split(" "))
	dic[A].append(B)
	dic[B].append(A)

for i in range(N):
	cnt = 0
	s = set([])
	for n in dic[i+1]:
		if n == (i+1):
			continue
		s = (s | (set(dic[n]) - set(dic[i+1])))
	print(len(s))