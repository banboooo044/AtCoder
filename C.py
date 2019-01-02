from math import sqrt
txa,tya,txb,tyb,T,V = map(int,input().split(" "))
n = int(input())
flg = False
for i in range(n):
	x,y = map(int,input().split(" "))
	t = (sqrt(((abs(txa - x))**2 + (abs(tya - y))**2)) + sqrt(((abs(txb - x))**2 + (abs(tyb - y))**2)))/V
	if t <= T:
		flg = True

if flg:
	print("YES")
else:
	print("NO")

