def ncr(n, r):
    r = min(r, n - r)
    if r == 0: return 1;
    if r == 1: return n;
    numerator = [n - r + i + 1 for i in range(r)]
    denominator  = [i + 1 for i in range(r)]
    for p in range(2, r + 1):
        pivot = denominator[p - 1]
        if pivot > 1:
            offset = (n - r) % p
            for k in range(p - 1, r, p):
                numerator[k - offset] /= pivot
                denominator[k] /= pivot
    result = 1
    for k in range(r):
        if numerator[k] > 1: 
            result *= numerator[k]
            
    return result

can = []
for i in range(50):
    can.append(ncr(50,i))

print(max(can))
