import math
N = int(input())
a = list(map(int,input().split(" ")))

ave = sum(a) // N
candidate = [ave-1,ave,ave+1]

ans = float('inf')
for num in candidate:
	sumv = 0
	for i in range(N):
		sumv += ((a[i]-num)**2)

	if ans > sumv:
		ans = sumv

print(ans)

