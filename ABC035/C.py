N,Q = map(int,input().split(" "))
s = 0
for i in range(Q):
	l,r = map(int,input().split(" "))
	bit = (1 << (N-l+1)) - (1 << (N-r))
	s ^= bit

ans = ""
for i in range(N-1,-1,-1):
	if (s >> i) & 1:
		ans += '1'
	else:
		ans += '0'

print(ans)