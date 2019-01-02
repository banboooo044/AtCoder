N = int(input())
s = input()
cnt = 0
acce = [0]*N
accw = [0]*N
if s[0] == 'E':
	acce[0] = 1
else:
	accw[0] = 1
for i in range(1,N):
	if s[i] == 'E':
		acce[i] = acce[i-1]+1
		accw[i] = accw[i-1]
	else:
		accw[i] = accw[i-1]+1
		acce[i] = acce[i-1]

m = acce[N-1] - acce[0]
for i in range(1,N):		
	if m > (accw[i-1]+(acce[N-1]-acce[i])):
		m = (accw[i-1]+(acce[N-1]-acce[i]))


print(m)
 

