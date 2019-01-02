N = int(input())
prev_t = 0
now = [0] * 2
for i in range(N):
	t,x,y = map(int,input().split(" "))

	dis = abs(x-now[0]) + abs(y-now[1])
	if (t - prev_t - dis)%2 == 0 and (dis <= t-prev_t):
		now = [x,y]
		prev_t = t
	else:
		print("No")
		exit(0)

print("Yes")


