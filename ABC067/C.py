N = int(input())
a = list(map(int,input().split(" ")))
ans = []
sumval = sum(a)
if N == 2:
	print(abs(a[0]-a[1]))
	exit(0)
	
for i in range(N-2):
	a[i+1] += a[i]
	ans.append(abs(sumval-2*a[i+1]))

print(min(ans))


