N =  int(input())
S = input()
accw = [0]*(N+1)
acce = [0]*(N+1)
for i in range(N):
	if S[i] == 'E':
		acce[i+1] = acce[i]+1
		accw[i+1] = accw[i]
	else:
		accw[i+1] = accw[i]+1
		acce[i+1] = acce[i]


ans = acce[N]
for i in range(1,N-1):
	ans = min(ans,(acce[N]-acce[i+1]) + accw[i])
ans = min(accw[N-1],ans)

print(ans)
