N,M = map(int,input().split(" "))
l = 1
r = N
for i in range(M):
    L,R = map(int,input().split(" "))
    l = max(l,L)
    r = min(r,R)

if r - l < 0:
    print(0)
else:
    print(r-l+1)