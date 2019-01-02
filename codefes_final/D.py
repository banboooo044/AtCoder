# D問題
import heapq
N = int(input())
heap = []

for i in range(N):
	H,P = map(int,input().split(" "))
	heap.append((P,H))

heapq.heapify(heap)

height = 0
count = 0

while heap != []:
	man = heapq.heappop(heap)
	if man[1] >= height:
		height += man[0]
		count += 1 


print(count)