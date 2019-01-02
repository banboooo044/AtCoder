import math
N,M,D = map(int,input().split(" "))
if M != 0:
	A = list(map(int,input().split(" ")))
else:
	for i in range(1,N+1):
		print(i)
	exit(0)

line = [ i for i in range(N)]
for i in range(M):
	line[A[i]-1],line[A[i]] = line[A[i]],line[A[i]-1]

d = int(math.log2(D)) + 1
move = [[0]*N for _ in range(d+1)]
for i in range(N):
	move[0][line[i]] = i

for i in range(1,d+1):
	for j in range(N):
		move[i][j] = move[i-1][move[i-1][j]]

line = [ i for i in range(N)]
for i in range(d+1):
	if (D >> i & 1):
		for j in range(N):
			line[j] = move[i][line[j]]

for i in range(N):
	print(line[i]+1)
