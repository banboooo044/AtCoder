N = int(input())
NG1 = int(input())
NG2 = int(input())
NG3 = int(input())
ng = [NG1,NG2,NG3]
ng.sort(reverse=True)

if N in ng:
	print("NO")
	exit(0)

if ng[0] == (ng[1]+1) == (ng[2]+2) and (ng[0] < N):
	print("NO")
	exit(0)

ng = list(map(lambda x:(N - x)%3,ng))
ng.append(N%3)

def dfs(n,plus,ng,sumv):
	if n == 3:
		if ng[n] == 0:
			return (plus,sumv)
		else:
			return (plus+1,sumv+(3-ng[n]))

	if ng[n] != 0:
		return dfs(n+1,plus,ng,sumv)

	else:
		a = dfs(n+1,plus+1,list(map(lambda x:(x-1)%3,ng)),sumv+1)
		b = dfs(n+1,plus+1,list(map(lambda x:(x-2)%3,ng)),sumv+2)
		return min(a,b)

cnt = dfs(0,0,ng,0)
if ((N - cnt[1])//3) + cnt[0] > 100:
	print("NO")
else:
	print("YES")

