N , K = map(int,input().split(" "))

ans = (6*(N-K)*(K-1) + 3 * (N-1) + 1) / (N**3)
print(ans)