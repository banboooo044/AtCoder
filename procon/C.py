import heapq
N = int(input())
x = list(map(int,input().split(" ")))
c = list(map(int,input().split(" ")))
v = list(map(int,input().split(" ")))

cv = [(C,V) for C,V in zip(c,v)]

cv.sort(key=lambda x: x[1])

money = 0
ans = 0
save = 0
for i in range(N):
	print(cv)
	money += x[i]
	tmp_money = money
	tmp = 0
	save += 1 
	for cost,val in cv[::-1]:
		if cost <= tmp_money:
			if 0 < save:
				cv.remove((cost,val))
				save -= 1
			else:
				tmp_money -= cost
				tmp += val

	ans = max(ans,tmp)
	print(ans)

print(ans)






