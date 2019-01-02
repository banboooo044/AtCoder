N = int(input())
A = {}
for i in range(N):
	a = int(input())
	if a in A:
		A.pop(a)
	else:
		A[a] = 1

print(len(A))
