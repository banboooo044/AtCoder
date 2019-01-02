N,M = map(int,input().split(" "))

def gcd(a, b):
	while b:
		a, b = b, a % b

	return a

# N > M
tmp_m = max([M,N])
tmp_n = min([M,N])
gcd_v = gcd(tmp_m,tmp_n)

ans = M - gcd_v

print(ans)