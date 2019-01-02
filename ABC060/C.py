N,T = map(int,input().split(" "))
t = list(map(int,input().split(" ")))
scope = [[t[0],t[0]+T]]

for i in range(1,N):
	if t[i] < scope[-1][1]:
		scope[-1][1] = t[i] + T

	else:
		scope.append([t[i],t[i]+T])

total = 0
for begin,end in scope:
	total += (end - begin)

print(total)

	
