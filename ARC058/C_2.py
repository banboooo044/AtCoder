import bisect
n,K = map(str,input().split(" "))
D = list(map(int,input().split(" ")))
N = list(n)

D_bar = []
for i in range(10):
	if not i in D:
		D_bar.append(i)

mv = str(D_bar[0])
ld = 10 - int(K)
l = len(N)
index = -1
for i in range(l):
	if int(N[i]) in D:
		index = i
		break

if index == (-1):
	print(n)
	exit(0)

for i in range(index,-1,-1):
	p = bisect.bisect_left(D_bar,int(N[i]))
	if p == ld:
		N[i] = mv
		if i == 0:
			m = str(D_bar[0]) if D_bar[0] != 0 else str(D_bar[1])
			N[0] = mv
			N.insert(0,m)
		else:
			N[i-1] = str(int(N[i-1]) + 1)
	else:
		N[i] = str(D_bar[p])
		break

for i in range(index+1,len(N)):
	N[i] = mv
print(''.join(N))