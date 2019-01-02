from collections import deque
N = int(input())
a = list(map(int,input().split(" ")))
b = deque([a[0]])

for i in range(1,N):
	b.appendleft(a[i]) if i % 2 == 1 else b.append(a[i])

if N % 2 == 1:
	b.reverse()

for i in range(N):
	print(b[i],end=" ")

print()



