N = int(input())
A = list(map(int,input().split(" ")))

s = sum(list(map(lambda x: int(x < 0),A)))
absA = sorted(list(map(lambda a: abs(a), A)))

if s % 2 == 1:
    print(-2*absA[0]+sum(absA))
else:
    print(sum(absA))