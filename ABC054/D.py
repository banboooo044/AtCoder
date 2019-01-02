if __name__ == "__main__":

	# dp[i][aの量][bの量] := minmoney

	INF = float('inf')


	N,Ma,Mb = map(int,input().split(" "))

	dp = [[[INF] * (Mb+1) for _ in range(Ma+1)]for i in range(N+1)]
	#初期化
	for i in range(1,N+1):
		dp[i][0][0]= 0

	for i in range(Ma+1):
		for j in range(Mb+1):
			dp[0][i][j] = 0


	A = [0] * N
	B = [0] * N
	C = [0] * N 

	for i in range(N):
		a,b,c = map(int,input().split(" "))
		A[i] = a
		B[i] = b
		C[i] = c


	for i in range(1,N+1):
		for a in range(0,Ma+1):
			for b in range(0,Mb+1):
				if a - A[i-1] >=  0 and b - B[i-1] >= 0:
					dp[i][a][b] = min([dp[i-1][a-A[i-1]][b-B[i-1]] + C[i-1],dp[i-1][a][b]])
				else:
					dp[i][a][b] = dp[i-1][a][b]

	print(dp)


	print(dp[N][Ma][Mb])





