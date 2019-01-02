N = int(input())
NG1 = int(input())
NG2 = int(input())
NG3 = int(input())
ng = [NG1,NG2,NG3]
ng.sort()

if N in ng:
	print("NO")
	exit(0)

if ng[0] == (ng[1]-1) == (ng[2]-2):
	print("NO")
	exit(0)

if ng[1] == (ng[2]-1):
	if (N - (ng[2]+1))%3 == 0:
		cnt = ((N - (ng[2]+1))//3)+1
	else:
		cnt = ((N - (ng[2]+1))//3)+2
	N = ng[1]-1
	if (N - ng[0])%3 == 0:
		N = (ng[0]-1)
		cnt += (((N - ng[0])//3)+1)
	cnt += (N//3) if N % 3 == 0 else ((N//3)+1)
	if cnt <= 100:
		print("YES")
	else:
		print("NO")
	exit(0)

if ng[0] == (ng[1]-1):
	cnt = 0
	if (N - ng[2]) % 3 == 0:
		N = (ng[2]-1)
		cnt += (((N - ng[2])//3)+1)
	
	if (N - (ng[1]+1)) % 3 == 0:
		cnt += (((N - (ng[1]+1))//3)+1)
	else:
		cnt += (((N - (ng[1]+1))//3)+2)
	N = ng[0]-1
	if N %3 == 0:
		cnt += (N//3)
	else:
		cnt += ((N//3)+1)

	if cnt <= 100:
		print("YES")
	else:
		print("NO")
	exit(0)
cnt = 0
ng.reverse()
flg = 0
ng = list(map(lambda x:(N - x)%3,ng))
print(ng)

if N % 3 == 0:
	cnt += (N//3)
else:
	cnt += ((N//3)+1)

for i

if cnt <= 100:
	print("YES")
else:
	print("NO")




