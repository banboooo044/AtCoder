N = int(input())
A = int(input())
B = int(input())
C = int(input())
D = int(input())
E = int(input())

m = min([A,B,C,D,E])
ans = N // m if N % m != 0 else (N // m) - 1

print(ans + 5)