N,K = map(int,input().split(" "))
s = [0]*N
for i in range(N):
	s[i] = int(input())

if N == 1:
	if s[0] <= K:
		print(1)
	else:
		print(0)
	exit(0)

if 0 in s:
	print(N)
	exit(0)

v = s[0]
l,r = 0,1
ans = 0
while True:
	while r < (N) and v*s[r] <= K:
		v *= s[r]
		r += 1
	ans = max(r - l,ans)
	if r >= (N):
		break
	if l != r:
		v //= s[l]
		l += 1
	else:
		r += 1
		v *= s[l]
print(ans)
