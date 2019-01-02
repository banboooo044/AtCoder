N = int(input())
a = list(map(int,input().split(" ")))
a.append(0)
a.insert(0,0)
dis = 0
for i in range(N+1):
	dis += (abs(a[i+1] - a[i]))


for i in range(N):
	ans = dis - abs(a[i+1] - a[i]) - abs(a[i+2] - a[i+1]) + abs(a[i+2] - a[i])
	print(ans)