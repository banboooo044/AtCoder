from itertools import product
N,M = map(int,input().split(" "))
x,y,z = [0]*N,[0]*N,[0]*N
for i in range(N):
	x[i],y[i],z[i] = map(int,input().split(" "))
ans = 0
for a,b,c in product(range(2),repeat=3):
	xyz = [0]*N
	for i in range(N):
		xyz[i] = (xyz[i] + x[i]) if a % 2 == 1 else (xyz[i] - x[i])
		xyz[i] = (xyz[i] + y[i]) if b % 2 == 1 else (xyz[i] - y[i])
		xyz[i] = (xyz[i] + z[i]) if c % 2 == 1 else (xyz[i] - z[i])
	xyz.sort(reverse=True)
	ans = max(sum(xyz[:M]),ans)
print(ans)