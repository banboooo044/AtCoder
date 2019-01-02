N,K = map(int,input().split(" "))
sumv = 1
s = [0] * N
l = 0
ans = 0
if N == 1:
	s = int(input())
	if s <= K:
		print(1)
	else:
		print(0)
	exit(0)

for i in range(N):
	s[i] = int(input())
	if s[i] == 0:
		ans = N
	sumv *= s[i]
	while sumv > K and l <= i:
		sumv //= s[l]
		l += 1
	
	else:
		ans = max(ans,i-l+1) if i != l or s[i] <= K else max(ans,0)
print(ans)