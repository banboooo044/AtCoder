N,M,A,B = map(int,input().split(" "))

if 2 * (A+B) > N*M:
	print("NO")
	exit(0)


def rec(N,M,A,B):
	if A <= 0 and B <= 0:
		return 1

	if A >= B:
		h = A // (M // 2)
		if h == 0:
			if N % 2 == 1:
				B -= ((N - 2) // 2) * A
				return rec(N,M-A,0,B)
			else:
				B -= ((N - 2) // 2) * (A // 2)
				return rec(N,M-A//2,0,B)



		A = A % (M // 2)
		if M % 2 == 1:
			B -= h

		return rec((N-h),M,A,B)

	else:
		l = B // (N // 2)
		if l == 0:
			return N,M,A,B
		B = B % (N // 2)
		if N % 2 == 1:
			A -= l
		return rec(N,(M-l),A,B)

n,m,a,b = rec(N,M,A,B)
arr = [[0]*m for _ in range(n)]
for i in range(A):








