import random
n = 10
print(n)
N = n
D = [[0] * N for _ in range(N)]

for i in range(n):
	for j in range(n):
		num = random.randint(1,30)
		D[i][j] = num
		print(num,end=" ")
	print()

mval = [0]*(N*N+1)

for i in range(1,N+1):
    tmp = [[sum(x[j:j+i]) for j in range(N+1-i)] for x in D]
    ttmp = list(zip(*tmp))
    for k in range(1,N+1):
        a = max([max([sum(x[j:j+k]) for j in range(N+1-k)]) for x in ttmp])
        if mval[k*i] < a:
            mval[k*i] = a


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


ans = [-1] * (N*N+1)
for i in range(N):
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
for i in range(1,N*N):
	ans[i+1] = max(ans[i],ans[i+1])


for q in range(1,N*N+1):
    if ans[q] != max(mval[:q+1]):
    	print("error")
    	print(q)
    	print(ans[q])
    	print(max(mval[:q+1]))
    	print("------------------")
    	print(mval)
    	print()
    	print(ans)
    	exit(0)


