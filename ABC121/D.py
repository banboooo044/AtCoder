def getXor(n):
    ret = 0
    i = 1
    while True:
        div,mod = divmod(n,i)
        flg = i * (div // 2)
        if div % 2 == 1:
            flg += (mod + 1)
        if flg % 2 == 1:
            ret += i
        i *= 2
        if i > n:
            break
    
    return ret

A,B = map(int,input().split(" "))
print(getXor(A-1) ^ getXor(B))