N,T = map(int,input().split(" "))
A = list(map(int,input().split(" ")))

minA = [(-1,-1)] * (N)
maxA = [(-1,-1)] * (N)

maxA[N-1] = (A[-1],1)
minA[0] = (A[0],1)
for i in range(1,N):
	if A[i] == minA[i-1][0]:
		minA[i] = (A[i],minA[i-1][1]+1)
	else:
		minA[i] = (min(minA[i-1][0],A[i]),1)

	if A[N-i-1] == minA[N-i][0]:
		minA[N-i-1] = (A[N-i-1],minA[N-i][1] + 1)
	else:
		maxA[N-i-1] = (max(maxA[N-i][0],A[N-i-1]),1)

pair = {}
prev = maxA[1][0] - minA[0][0]
for i in range(N-1):
	if prev < (maxA[i+1][0] - minA[i][0]):
		pair = {(maxA[i+1][0],minA[i][0]) : min(maxA[i+1][1],minA[i][1])}
		prev = (maxA[i+1][0] - minA[i][0])
	elif prev == (maxA[i+1][0] - minA[i][0]):
		if (maxA[i+1][0],minA[i][0]) in pair:
			pair[(maxA[i+1][0],minA[i][0])] = max(pair[(maxA[i+1][0],minA[i][0])],min(maxA[i+1][1],minA[i][1]))
		else:
			pair[(maxA[i+1][0],minA[i][0])] = min(maxA[i+1][1],minA[i][1])

print(sum(pair.values()))