import bisect
N,K = map(str,input().split(" "))
D = list(map(int,input().split(" ")))
D_bar = []
for i in range(10):
	if not i in D:
		D_bar.append(i)

ld = len(D_bar)
l = len(N)

mv = str(D_bar[0]) if D_bar[0] != 0 else str(D_bar[1])
ans = N
if int(N[0]) in D:
	p = bisect.bisect_left(D_bar,int(N[0]))
	if p == ld:
		ans = mv + str(D_bar[0])*(l)
	else:
		ans = str(D_bar[p]) + str(D_bar[0])*(l-1)

else:
	for i in range(1,l):
		num = int(N[i])
		if num in D:
			p = bisect.bisect_left(D_bar,num)
			if p == ld:
				ans = N[:i-1] + mv + (str(D_bar[0])*max(0,l-i))
			else:
				ans = N[:i] + str(D_bar[p]) + (str(D_bar[0])*max(0,l-i-1))

			break

print(ans)




