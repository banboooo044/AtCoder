import sys
sys.setrecursionlimit(100000000)
N = int(input())
E = [dict() for _ in range(N+1)]
for i in range(N-1):
	a,b = map(int,input().split(" "))
	E[a][b] = 1
	E[b][a] = 1

fen_count = -1
chil = [0] * (N+1)
def dfs(ver,prev,route):
	global fen_count
	global chil

	fen_count += 1
	flag = -1
	tmp_route = route[:]
	tmp_route.append(ver)
	for nextver in E[ver].keys():
		if nextver == prev:
			pass
		elif nextver == N:
			flag = 1
		else:
			chil[ver] += 1
			lis = dfs(nextver,ver,tmp_route)
			if len(lis) >= 2:
				flag = 1
				tmp_route = lis[:]

	if flag == 1:
		return tmp_route
	else:
		return [0]

route = dfs(1,-1,[])
l = len(route) -1
i = l//2
if i != 0:
	for j in range(i,0,-1):
		fen_count -= (chil[route[-j]])
	fen_count -= 1

if fen_count > (N-2-fen_count):
	print("Fennec")
else:
	print("Snuke")

			


