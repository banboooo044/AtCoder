#いもす法
N,M = map(int,input().split(" "))
jewel = [0]*M
sums = 0
for i in range(N):
	l,r,s = map(int,input().split(" "))
	jewel[l-1] += (-s)
	if r < M:
		jewel[r] += s
	sums += s


for i in range(M-1):
	jewel[i+1] += jewel[i]
jewel = list(map(lambda x: x+sums,jewel))
print(max(jewel))