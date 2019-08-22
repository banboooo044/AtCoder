N, M = map(int,input().split(" "))
X =  list(map(int,input().split(" ")))

X.sort()
dif = [ X[i+1] - X[i] for i in range(M-1) ]
dif.sort()
add = max(0,M - N)
print(sum(dif[:add]))