N,Q = map(int,input().split(" "))
A = list(map(int,input().split(" ")))
X = [0] * Q

accAll = [0] * N
accAll[0] = A[0]
accEven = [0] * N
accEven[0] = A[1]
accOdd = [0] * N
accOdd[0] = A[0]
for i in range(N-1):
    accAll[i+1] = accAll[i] + A[i+1]
    if i % 2 == 1 and i < (N-2):
        accEven[(i+1)//2] =  accEven[i//2] + A[i+2]
    if i % 2 == 0 and i < (N-2):
        accOdd[(i+2)//2] = accOdd[i//2] + A[i+2]

tk_num = N // 2 if N % 2 == 0 else (N // 2) + 1
for i in range(Q):
    X[i] = int(input())
    ng,ok = -1,N
    while abs(ok-ng) > 1:
        mid = (ok + ng) // 2
        if X[i] <= A[mid]:
            ok = mid
        else:
            ng = mid

    if (ok < N and ok > 0 and (A[ok]-X[i]) < (X[i]-A[ok-1])):
        ok += 1

