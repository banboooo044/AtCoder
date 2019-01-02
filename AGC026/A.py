N = int(input())
A = list(map(int,input().split(" ")))
prev = A[0]
cnt = 0
for i in range(1,N):
	if prev == A[i]:
		cnt += 1
		prev = (-1)
	else:
		prev = A[i]

print(cnt)
