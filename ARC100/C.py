N = int(input())
A = list(map(int,input().split(" ")))
for i in range(N):
	A[i] -= (i+1)
A.sort()
if N % 2 == 1:
	b = A[(N//2)]
	ans = list(map(lambda x:abs(x-b),A))
	print(sum(ans))
else:
	b1 = (A[N//2-1] + A[(N//2)])//2
	ans1 = list(map(lambda x:abs(x-b1),A))
	b2 = b1 + 1
	ans2 = list(map(lambda x:abs(x-b2),A))
	print(min(sum(ans1),sum(ans2)))