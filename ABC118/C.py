from functools import reduce
def gcd (a: int,b: int) -> int:
    if a < b: a,b = b,a
    return a if b == 0 else gcd(b,a%b)
N = int(input())
print(reduce(gcd,list(map(int,input().split(" ")))))