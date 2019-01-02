N = int(input())
a = list(map(int,input().split(" ")))
ans = -float('inf')
for i in range(N):
	pretak = -float('inf')
	preaok = -float('inf')
	for j in range(N):
		tak = 0
		aok = 0
		cnt = 1
		if i < j:
			for k in range(i,j+1):
				if cnt % 2:
					tak += a[k]
				else:
					aok += a[k]
				cnt += 1

			if aok > preaok:
				pretak = tak
				preaok = aok


		elif i > j:
			for k in range(j,i+1):
				if cnt % 2:
					tak += a[k]
				else:
					aok += a[k]
				cnt += 1

			if aok > preaok:
			 	pretak = tak
			 	preaok = aok

	if ans < pretak:
		ans = pretak

print(ans)
