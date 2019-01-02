N,D = map(int,input().split(" "))
X = list(map(int,input().split(" ")))

in_D = [0]*N
ex_D = [0]*N
for i in range(N):
	lb = (i)
	ub = (N-1)
	bound = (N-1)
	while lb <= ub:
		mid = (lb + ub) //2
		if X[mid] - X[i] <= D:
			lb = mid + 1
			bound = mid
		else:
			ub = mid - 1
	ex_D[i] = (N - 1 - bound)
	in_D[i] = bound

for i in range(N-1):
	ex_D[i+1] += ex_D[i]
print(ex_D)

pat = 0
for i in range(N):
	if (N - 1 - in_D[i]) >= 2:
		pat += ((N - 1 - in_D[i])*(N - 2 - in_D[i])//2)
	if (in_D[i] - i >= 2):
		pat += ((in_D[i] - i)*(in_D[i] - i - 1)//2)
	pat += (ex_D[in_D[i]] - ex_D[i])

print((N*(N-1)*(N-2)//6) - pat)

