from scipy.misc import comb
N = int(input())
cnt = 1
A = list(map(int,input().split(" ")))
M = []

for i in range(1,N):
	if A[i] > A[i-1]:
		cnt += 1
	else:
		M.append(cnt)
		cnt = 1

M.append(cnt)
m = len(M)
ans = 0
for i in range(m):
	if M[i] != 1:
		ans += comb(M[i],2)
ans = int(round(ans,1))
print(ans+N)