N = int(input())
t,a = map(int,input().split(" "))
for i in range(N-1):
	T,A = map(int,input().split(" "))
	if a % A == 0:
		pla = a // A
	else:
		pla = (a + (A - a % A)) // A

	if t % T == 0:
		plt = t // T
	else:
		plt = (t + (T - t % T)) // T
	t = max(pla,plt) * T
	a = max(pla,plt) * A

print(t+a)
