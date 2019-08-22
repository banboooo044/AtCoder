if __name__ == '__main__':
    N, W = map(int,input().split(" "))
    w,v = [0]*(N+1),[0]*(N+1)
    for i in range(N):
        w[i+1],v[i+1] = map(int,input().split(" "))

    V = sum(v)
    dp = [ [float('inf')]*(V+1) for _ in range(N+1) ]
    for i in range(N+1):
        dp[i][0] = 0

    for i in range(1,N+1):
        for j in range(1,V+1):
            if j >= v[i]:
                dp[i][j] = min([dp[i][j],dp[i-1][j],dp[i-1][j-v[i]] + w[i]])
            else:
                dp[i][j] = min([dp[i][j],dp[i-1][j]])

    for j in range(V,-1,-1):
        if dp[N][j] <= W:
            print(j)
            break

