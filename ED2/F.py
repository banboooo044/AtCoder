import sys
def solve():
    # dp[i][j] = LCS(s[:i+1],t[:j+1])
    sLen, tLen = len(s),len(t),
    dp = [ [( 0 , -1 )]*(tLen+1)  for _ in range(sLen+1) ]
    for i in range(1,sLen+1):
        for j in range(1,tLen+1):
            comp = [ dp[i][j-1][0],dp[i-1][j-1][0]+int(s[i-1]==t[j-1]),dp[i-1][j][0]]
            argmax = comp.index(max(comp))
            dp[i][j] = ( comp[argmax] , argmax )

    ans = ""
    i,j = sLen, tLen
    for _ in range(sLen+tLen):
        if dp[i][j][1] == 0:
            j -= 1
        elif dp[i][j][1] == 1:
            ans += s[i-1]
            i -= 1
            j -= 1
        elif dp[i][j][1] == 2:
            i -= 1
        else:
            break
    return ans[::-1]

if __name__ == '__main__':
    s = sys.stdin.readline()
    t = sys.stdin.readline()
    print(solve())