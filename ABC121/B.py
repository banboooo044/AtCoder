from functools import reduce
N,M,C = map(int,input().split(" "))
B = list(map(int,input().split(" ")))

ans = 0
for i in range(N):
    A = list(map(int,input().split(" ")))
    s = reduce(lambda x,y:x+y,[ a*b for a,b in zip(A,B) ]) + C 
    if s > 0:
        ans += 1

print(ans)
