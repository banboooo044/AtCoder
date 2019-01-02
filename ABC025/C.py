from itertools import combinations

b1 = list(map(int,input().split(" ")))
b2 = list(map(int,input().split(" ")))
sumv = sum(b1) + sum(b2)
b = [b1,b2]
c1 = list(map(int,input().split(" ")))
c2 = list(map(int,input().split(" ")))
c3 = list(map(int,input().split(" ")))
c = [c1,c2,c3]
sumv += sum(c1) + sum(c2) + sum(c3)
for first in range(9):
	x = first//3,y = first%3
	flg = [[False]*3 for _ in range(3)]
	while True:
		cand = []
		if (x - 1) >= 0 and flg[x-1][y]:
			cand.append((b[x-1][y],x-1,y))
		if (x + 1) < 3 and flg[x+1][y]:
			cand.append((b[x][y],x+1,y))
		if (y - 1) >= 0 and flg[x][y-1]:
			cand.append((c[x][y-1],x,y-1))
		if (y + 1) < 3 and flg[x][y+1]:
			cand.append((b[x][y],x,y+1))

		if cand == []:
			break
		m = max(cand)
		flg[cand[1]][cand[2]] = True
		choku += m
		x,y
