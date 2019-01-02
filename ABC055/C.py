N,M = map(int,input().split(" "))

if M // 2 <= N:
	print(M//2)

else:
	M -= (N*2)
	print(N+M//4)

