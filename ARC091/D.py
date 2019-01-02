N,K = map(int,input().split(" "))
ans = 0
for b in range(K+1,N+1):
	k = ((N - K) // b)
	num = min(((N - K) % b) + 1,b-K)
	ans += ((b - K) * (k + 1) - ((b - K) - num))
if K == 0:
	print(ans - N)
else:
	print(ans)