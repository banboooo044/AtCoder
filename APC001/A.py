X,Y = map(int,input().split(" "))
if Y == 1:
	print(-1)
	exit(0)

if X < Y:
	print(X)
	exit(0)

if X % Y == 0:
	print(-1)
else:
	print(X)

