T = int(input())

def gcd (a: int,b: int) -> int:
    if a < b: a,b = b,a
    return a if b == 0 else gcd(b,a%b)
def lcm (a: int,b: int) -> int:
    return a // gcd(a,b) * b


for i in range(T):
    A,B,C,D = map(int,input().split(" "))
    g = gcd(B,D)
    if A < B or D < B:
        print("No")
        continue
    if C >= ((B - g) + (A % g)):
        print("Yes")
    else:
        print("No")

