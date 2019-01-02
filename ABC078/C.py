N,M = map(int,input().split(" "))

A = 100 * (N-M) + 1900 * M

ans =  A * (2**M) 

print(int(ans))