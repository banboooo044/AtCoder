N = int(input())
info = []
arrive = []
for i in range(N-1):
	info.append(list(map(int,input().split(" "))))


for i in range(N-1):
	C = info[i][0]
	S = info[i][1]
	F = info[i][2]
	next_arrive = []
	for j in arrive:
		if j <= S:
			next_arrive.append(S+C)
		else:
			if j % F == 0:
				next_arrive.append(j+C)
			else:
				cnt = F * ((j // F) + 1)
				next_arrive.append(cnt+C)

	next_arrive.append(S+C)
	arrive = next_arrive[:]

arrive.append(0)

for ans in arrive:
	print(ans)
