# 50Cr はmaxで126410606437752なので間に合わない。TLE解法
from itertools import combinations
N,K = map(int,input().split(" "))
point = []

for i in range(N):
	x,y = map(int,input().split(" "))
	point.append((x,y))

ans = float('inf')

for num in combinations(range(N),K):
	x_min = y_min = float('inf')
	x_max = y_max = -float('inf')

	for i in num:
		x_min = min([x_min,point[i][0]])
		x_max = max([x_max,point[i][0]])
		y_min = min([y_min,point[i][1]])
		y_max = max([y_max,point[i][1]])

	x = x_max - x_min
	y = y_max - y_min
	ans = min([ans,x*y])

print(ans) 

