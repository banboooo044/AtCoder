N,K = map(int,input().split(" "))
a = list(map(int,input().split(" ")))

val = sum(a[:K])
sumv = val
for i in range(N-K):
	val += (sumv - a[i] + a[K+i])
	sumv = (sumv - a[i] + a[K+i])

print(val)