N = int(input())
A1 = list(map(int,input().split(" ")))
A2 = list(map(int,input().split(" ")))

for i in range(N-1):
	A1[i+1] += A1[i]
	A2[i+1] += A2[i]

ans = A1[0] + A2[N-1]
for i in range(1,N):
	ans = max(ans,A1[i] + A2[N-1] - A2[i-1])

print(ans)