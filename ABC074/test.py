import random
n = random.randint(1,10)
print(n)
e = [[0]*n for _ in range(n)]

for i in range(n):
	for j in range(i+1,n):
		a = random.randint(1,10)
		e[i][j] = e[j][i] = a


for i in range(n):
	for j in range(n):
		print(str(e[i][j]) + " ", end='')
	print()