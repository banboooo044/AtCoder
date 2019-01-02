N = int(input())
A = [[] for _ in range(N)]
E = [[0]*(N) for _ in range(N) ]

for i in range(N):
	A[i] = list(map(int,input().split(" ")))

ans = 0
for i in range(N):
	for j in range(N):
		flag = 0
		if i == j:
			continue
		for k in range(N):
			if i == k or j == k:
				continue

			if A[i][j] == A[i][k] + A[k][j]:
				E[i][k] = E[k][i] = E[k][j] = E[j][k] = 1
				flag = 1

			elif A[i][j] > A[i][k] + A[k][j]:
				print(-1)
				exit(0)

			else:
				pass

		if flag == 0:
			E[i][j] = E[j][i] = 1


for i in range(N):
	for j in range(N):
		if E[i][j] == 1:
			ans += A[i][j]

print(ans//2)