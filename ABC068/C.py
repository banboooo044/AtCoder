N,M = map(int,input().split(" "))
a_to = []
N_to = []
for i in range(M):
	a, b = map(int,input().split(" "))
	if a == 1 or b == 1:
		a_to.append(max(a,b))
	elif b == N or a == N:
		N_to.append(min(a,b))

a_set = set(a_to)
N_set = set(N_to)

if (len(a_set&N_set) >= 1):
	print("POSSIBLE")
else:
	print("IMPOSSIBLE")
