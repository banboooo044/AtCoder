N,A,B,K = map(int,input().split(" "))
mod = 998244353
ncr = [1]*(N+1)
v = 1
for i in range(N):
	v = (v * ((N-i)%mod) * pow((i+1),mod-2,mod)) % mod
	ncr[i+1] = v%mod

pat = 0
for a in range(N+1):
	if (K - (a * A) < 0):
		break
	if (K - (a * A)) % B == 0 and ((K - (a * A))//B) <= N:
		pat += ncr[a]*ncr[(K - (a * A))//B]
		pat %= mod

print(pat % mod)

