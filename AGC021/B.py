from math import atan
N = int(input())
xy = []
for i in range(N):
	x,y = map(int,input().split(" "))
	xy.append([x,y,i])

xy.sort(key=lambda x:x[0])
base1 = xy[0]
base2 = xy[-1]
xy[1:].sort(key=lambda x:x[1])

def is_convex(P,x1,y1,x2,y2,base_y):
	f = lambda x:((y2-y1)/(x2-x1))*(x-x1)+y1 if (x2 - x1) != 0 else None
	if base_y < y2:
		return f(P[0]) < P[1]
	else:
		return f(P[0]) > P[1]

#上側
convex = [xy[0],xy[1]]
if N == 2:
	index = 1

for i in range(2,N):
	if base2 == xy[i]:
		index = i
		convex.append(base2)
		break

	while True:
		if is_convex(convex[-1],convex[-2][0],convex[-2][1],xy[i][0],xy[i][1],base1[1]):
			convex.append(xy[i])
			break
		else:
			convex.pop(-1)
			if len(convex) == 1:
				convex.append(xy[i])
				break

if index != (N-1):
	convex.append(xy[index+1])

for i in range(index+1,N):
	while True:
		if is_convex(convex[-1],convex[-2][0],convex[-2][1],xy[i][0],xy[i][1],base2[1]):
			convex.append(xy[i])
			break
		else:
			convex.pop(-1)
			if len(convex) == 1:
				convex.append(xy[i])
				break


convex[0] 