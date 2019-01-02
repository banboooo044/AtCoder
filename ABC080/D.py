import heapq
#D問題
#同じチャンネルの録画をすれば -0.5のラグはない 
heap = []
rec = 1
margin = 0
 
N,C = map(int,input().split(" "))
info = [(0,0,0)] * N
 
for i in range(N):
	a,b,c = map(int,input().split(" "))
	info[i] = (a,b,c)
 
info.sort()
 
heapq.heappush(heap,info[0][1])
for i in range(1,N):
	if (2 * heap[0]) <= ((2 * info[i][0]) - 1):
		heapq.heappop(heap)
 
		while True:
			if heap == []:
				break
			elif (2 * heap[0]) > (2 * info[i][0] - 1):
				break
			else:
				margin += 1
				heapq.heappop(heap)
 
		heapq.heappush(heap,info[i][1])
 
	else:
		if margin <= 0:
			rec += 1
		else:
			margin -= 1
 
		heapq.heappush(heap,info[i][1])
 
print(rec)



