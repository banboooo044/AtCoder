import queue as Q
w,h = map(int,input().split(" "))
n = int(input())
x = [0,w-1]
y = [0,h-1]
xs,ys,xg,yg = [0]*n,[0]*n,[0]*n,[0]*n
for i in range(n):
	xs[i],ys[i],xg[i],yg[i] = map(int,input().split(" "))
	x.append(xs[i])
	if xs[i] > 0:
		x.append(xs[i]-1)
	x.append(xg[i]-1)
	if xg[i] < w:
		x.append(xg[i]) 
	y.append(ys[i])
	if ys[i] > 0:
		y.append(ys[i]-1)
	y.append(yg[i]-1)
	if yg[i] < h:
		y.append(yg[i]) 
x = list(set(x))
y = list(set(y))
x.sort()
y.sort()
newx,newy = len(x),len(y)
dicx,dicy = {},{}
for i in range(newx):
	dicx[x[i]] = i
for i in range(newy):
	dicy[y[i]] = i

check = [[0]*newx for _ in range(newy)]
for i in range(n):
	p,q = dicx[xs[i]],dicy[ys[i]]
	t,s = dicx[xg[i]-1],dicy[yg[i]-1]
	check[q][p] += 1
	if t < (newx-1):
		check[q][t+1] += (-1)
	if s < (newy-1):
		check[s+1][p] += (-1)
	if t < (newx-1) and s < (newy-1):
		check[s+1][t+1] += 1

for i in range(newy):
	for j in range(newx-1):
		check[i][j+1] += check[i][j]

for i in range(newy-1):
	for j in range(newx):
		check[i+1][j] += check[i][j]

dx = [0,-1,0,1]
dy = [1,0,-1,0]
ans = 0
for i in range(newy):
	for j in range(newx):
		if check[i][j] != 0:
			continue
		ans += 1
		que = Q.Queue()
		que.put((j,i))
		check[i][j] = 1
		while not que.empty():
			a,b = que.get()
			for k in range(4):
				if (0 > b+dy[k]) or (b+dy[k] >= newy) or (0 > a+dx[k]) or (a+dx[k] >= newx):
					continue  
				if check[b+dy[k]][a+dx[k]] == 0:
					check[b+dy[k]][a+dx[k]] = 1
					que.put((a+dx[k],b+dy[k]))
print(ans)
