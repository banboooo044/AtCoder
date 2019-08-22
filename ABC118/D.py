N, M = map(int,input().split(" "))
A = list(map(int,input().split(" ")))

n = [2,5,5,4,5,6,3,7,6]

memo = [ ["-1"]*N  for _ in range(10) ]
def dfs(dig,num):
    if memo[dig][num] != "-1":
        return memo[dig][num]

    returnSet = []
    for a in A:
        if n[a-1] + num < N:
            ret = dfs(dig+1,num+n[a-1])
            if ret == "-1":
                continue
            else:
                returnSet.append(str(a)+ret)
        elif n[a-1] + num == N:
            returnSet.append(str(a))
    
    if returnSet == []:
        return "-1"
    memo[dig][num] = max(returnSet,key=lambda x: (len(x),x))
    return memo[dig][num]

print(dfs(0,0))
print(memo)
