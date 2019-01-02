A,B,N = map(int,input().split(" "))
X = input()

for i in range(N):
	if X[i] == 'S':
		A -= 1
	elif X[i] == 'C':
		B -= 1
	else:
		if A >= B:
			A -= 1
		else:
			B -= 1
print(max(A,0))
print(max(B,0))
