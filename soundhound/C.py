n,m,d = map(int,input().split(" "))
if d != 0:
	print(2*(n-d)*(m-1)/(n*n))
else:
	print((n)*(m-1)/(n*n))