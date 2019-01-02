K = int(input())
A = list(map(int,input().split()))

if A[-1] != 2:
	print(-1)
	exit(0)

minval = 2
maxval = 3
for i in range(K-1,-1,-1):
	if maxval < A[i] or (minval > A[i] and ((maxval - (maxval % A[i]) < minval))):
		print(-1)
		exit(0)

	if minval > A[i]:
		if minval % A[i] != 0:
			minval = minval + (A[i] - (minval % A[i]))

		maxval = (maxval - (maxval % A[i]) + A[i] - 1)

	else:
		maxval = A[i] + (A[i] - 1)
		minval = A[i]
		

print(str(minval) + " " + str(maxval))
