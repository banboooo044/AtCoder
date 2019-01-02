N,M = map(int,input().split(" "))
X,Y = map(int,input().split(" "))
a = list(map(int,input().split(" ")))
b = list(map(int,input().split(" ")))

t = 0
indA = 0
indB = 0
cnt = 0

flg = True
while flg:
	flg = False
	if indA >= N or indB >= M:
		break

	for i in range(indA,N):
		if a[i] >= t:
			t = a[i] + X
			indA = (i+1)
			flg = True
			break
	if not flg:
		break

	flg = False
	for i in range(indB,M):
		if b[i] >= t:
			t = b[i] + Y
			indB = (i+1)
			flg = True
			cnt += 1
			break

print(cnt)


