N = int(input())
h = list(map(int,input().split(" ")))

def rec(H,acc,l,r):
    if r - l == 1:
        return (H[l] - acc) 
    mn = min(H[l:r])
    mx = max(H[l:r])
    if mn == mx:
        return mn - acc
    flg = False
    ans = (mn - acc)
    L = 0
    for i in range(l,r):
        if H[i] != mn:
            if not flg:
                L = i
                flg = True

            if i == r-1:
                ans += rec(H,mn,L,r)
        else:
            if flg:
                ans += rec(H,mn,L,i)
            flg = False
    
    return ans
print(rec(h,0,0,N))