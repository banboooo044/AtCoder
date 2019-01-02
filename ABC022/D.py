import numpy as np
N = int(input())
f = lambda lisx,x,lisy,y: (abs(lisx-x)**2) + (abs(lisy-y)**2)
x = [0]*N
y = [0]*N
for i in range(N):
	x[i],y[i] = map(int,input().split(" "))

xg = float(sum(x)/N)
yg = float(sum(y)/N)
m = max(map(f,x,[xg]*N,y,[yg]*N))
#print(m)
for i in range(N):
	x[i],y[i] = map(int,input().split(" "))

xg = float(sum(x)/N)
yg = float(sum(y)/N)
m2 = max(map(f,x,[xg]*N,y,[yg]*N))

#print(m2)
print(np.sqrt(m2/m))
