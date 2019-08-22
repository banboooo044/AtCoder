import math
A,B ,K= map(int,input().split(" "))
def gcd (a: int,b: int) -> int:
    if a < b: a,b = b,a
    return a if b == 0 else gcd(b,a%b)
def lcm (a: int,b: int) -> int:
    return a // gcd(a,b) * b

g = gcd(A,B)

itermx = math.sqrt(g)+1
lst = []
for j in range(1,int(itermx+1)):
    if g % j == 0:
        lst.append(j)
        if g // j != j:
            lst.append(g//j)
lst.sort(reverse=True)
print(lst[K-1])
