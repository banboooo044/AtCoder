r = [[0]*100001 for _ in range()]
for i in range(1,100001):
	for j in range(1,100001):
		r[i][j] = r[i-1][j] + r[i][j-1]

print(r)
