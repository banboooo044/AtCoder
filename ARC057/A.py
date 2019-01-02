A,K = map(int,input().split(" "))
lim = 2 * (10 ** 12)
if K == 0:
	print(lim - A)
	exit(0)

cnt = 0
while A < lim:
	cnt += 1
	A += (1 + K * A)

print(cnt)