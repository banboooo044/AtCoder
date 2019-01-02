N = int(input())
N = 2025 - N
ans = []
for i in range(1,10):
	for j in range(i,10):
		if (i*j) == N:
			ans.append((i,j))

s = "{0} x {1}"
for tup in ans:
	print(s.format(tup[0],tup[1]))
for tup in ans[::-1]:
	if (tup[0] != tup[1]):
		print(s.format(tup[1],tup[0]))