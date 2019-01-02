
N,K = map(int,input().split(" "))
num = []

for i in range(N):
	a,b = map(int,input().split(" "))
	num.append([a,b])
num = list(sorted(num,key=lambda x:x[0]))

if num[0][1] >= K:
	print(num[0][0])
	exit(0)
for i in range(1,N):
	num[i][1] += num[i-1][1]
	if num[i][1] >= K:
		print(num[i][0])
		exit(0)
