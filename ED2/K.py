import sys
sys.setrecursionlimit(10000)
N, K = map(int,input().split(" "))
A = list(map(int,input().split(" ")))
memo = [-1] * (K+1)
for i in range(A[0]):
    memo[i] = 0

def grundy(n):
    if memo[n] != -1:
        return memo[n]
    grundySet = []
    for a in A:
        if a > n:
            break
        grundySet.append(grundy(n-a))
    grundySet.sort()
    num = 0
    for e in grundySet:
        if num != e:
            memo[n] = num
            return num
        else:
            num += 1
    
    memo[n] = num
    return num

grundyNum = grundy(K)
if grundyNum == 0:
    print("Second")
else:
    print("First")




