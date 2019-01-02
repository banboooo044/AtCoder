N = int(input())
A = list(map(int,input().split(" ")))

A.sort(reverse=True)
l = len(A)

if l % 2 == 1:
	if A[-1] != 0:
		print(0)
	else:
		num = (N-1)
		for i in range(0,N-1,2):
			if not (A[i] == A[i+1] == num):
				print(0)
				exit(0)
			num -= 2

		print(2 ** ((N - 1)//2))
else:
	num = (N-1)
	for i in range(0,N,2):
		if not (A[i] == A[i+1] == num):
			print(0)
			exit(0)
		num -= 2

	print((2 ** ((N)//2)) % ((10 ** 9)+7))










