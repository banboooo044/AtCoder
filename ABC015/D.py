#高橋くんの苦悩
#動的計画法

# dp[i][width] := (maxValue,useNum)

if __name__ == "__main__":
	INF = float('inf')

	W = int(input())
	N,K = map(int,input().split(" "))

	dp = [[0]*(W+1) for _ in range(K+1)]

	A = [0] * N
	B = [0] * N

	for i in range(N):
		a , b= map(int,input().split(" "))
		A[i] = a
		B[i] = b

	past_max = 0
	for i in range(N,0,-1):
		for useNum in range(min([N-i+1,K]),0,-1):
			for width in range(W+1):
				if width - A[i-1] >= 0 and useNum <= K:
					dp[useNum][width] = max([dp[useNum-1][width - A[i-1]] + B[i-1],dp[useNum][width]])
					past_max = max([past_max,dp[useNum][width]])

	print(past_max)
