W,H = map(int,input().split(" "))
N = int(input())

X = [0]*N
Y = [0]*N
xlis = [0,W]
ylis = [0,H]
for i in range(N):
	X[i],Y[i] = map(int,input().split(" "))
	xlis.append(X[i])
	xlis.append(X[i]-1)
	xlis.append(X[i]+1)
	ylis.append(Y[i])
	ylis.append(Y[i]-1)
	ylis.append(Y[i]+1)
xlis = list(set(xlis))
ylis = list(set(ylis))
xlis.sort()
ylis.sort()
dicx = {}
dicy = {}
for i,v in enumerate(xlis):
	dicx[v] = i
for i,v in enumerate(ylis):
	dicy[v] = i

print(dicx)
print(dicy)

