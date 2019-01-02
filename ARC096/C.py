A,B,C,X,Y = map(int,input().split(" "))
m = min(X,Y)
ans = m * min((A+B),(C+C))
X -= m
Y -= m
if X != 0:
	ans += (min(A,C+C) * X)
else:
	ans += (min(B,C+C) * Y)

print(ans)