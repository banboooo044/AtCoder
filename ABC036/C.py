N = int(input())
key = []
A = [0] * N
num = {}
for i in range(N):
	A[i] = int(input())
	if not A[i] in key:
		key.append(A[i])

key.sort()
l = len(key)
for i in range(l):
	num[key[i]] = i

for i in range(N):
	print(num[A[i]])



