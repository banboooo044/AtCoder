def max_arr(h,l):
	ans = D[h-1][l-1]
	for i in range(l,N):
		ans = max(D[h-1][i] - D[h-1][i-l],ans)
	for i in range(h,N):
		ans = max(D[i][l-1] - D[i-h][l-1],ans) 

	for i in range(h,N):
		for j in range(l,N):
			ans = max(ans,D[i][j] - D[i-h][j] - D[i][j-l] + D[i-h][j-l])

	return ans

N = int(input())
D = []
ans = [-1] * (N*N+1)
for i in range(N):
	D.append(list(map(int,input().split(" "))))
	ans[1] = max(max(D[i]),ans[1])

#累積和をとる
for i in range(N):
	for j in range(N-1):
		D[i][j+1] += D[i][j]

for j in range(N):
	for i in range(N-1):
		D[i+1][j] += D[i][j]

for j in range(2,N+1):
	ans[j] = max(max_arr(1,j),max_arr(j,1))

for i in range(2,N+1):
	ans[i*i] = max(max_arr(i,i),ans[i*i])
	for j in range(i+1,N+1):
		ans[i*j] = max([max_arr(i,j),max_arr(j,i),ans[i*j]])
		
Q = int(input())
for i in range(Q):
	q = int(input())
	print(max(ans[:q+1]))
