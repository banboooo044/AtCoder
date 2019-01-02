W,H = map(int,input().split())
MOD = 10**9+7

def mul(a,b):
    return (a*b) % MOD

def pow(a,n): # a^n
    ret = 1
    mag = a
    while n > 0:
        if n & 1:
            ret = mul(ret, mag)
        mag = mul(mag, mag)
        n >>= 1
    return ret

def inv(a):
    return pow(a, MOD-2)

fac = [1]
for n in range (1,W+H+2):
    f = mul(fac[n-1], n)
    fac.append(f)

def ncr(n,r):
    inv1 = inv(fac[n-r])
    inv2 = inv(fac[r])
    return mul(mul(fac[n], inv1), inv2)

print(W)
print(H)
print(ncr(W+H-2, W-1))
