# C問題
import heapq

N,K = map(int,input().split(" "))
que = []

A = [0] * N
B = [0] * N 

for i in range(N):
	a,b = map(int,input().split(" "))
	A[i] = a
	B[i] = b
	heapq.heappush(que,(a,b))

count = 0
time = 0
while True:
	if count == K:
		break 

	count += 1
	a = heapq.heappop(que)
	time += a[0]
	heapq.heappush(que,(a[0]+a[1],a[1]))

print(time)






	



