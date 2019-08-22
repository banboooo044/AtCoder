import sys 
input = sys.stdin.readline
def dfs(one,two,three):
    if memo[one][two][three] != -1:
        return memo[one][two][three]
    ret = 0
    if one > 0:
        ret += (dfs(one-1,two,three)*one)
    if two > 0:
        ret += (dfs(one+1,two-1,three)*two)
    if three > 0:
        ret += (dfs(one,two+1,three-1)*three)
    ret += N
    ret /= (one+two+three)
    memo[one][two][three] = ret
    return ret

if __name__ == '__main__':
    N = int(input())
    a = list(map(int,input().split(" ")))
    memo = [ [ [-1]*(N+1)  for i in range(N+1)] for j in range(N+1) ]
    memo[0][0][0] = 0
    one = a.count(1)
    two = a.count(2)
    three = a.count(3)
    print(dfs(one,two,three))