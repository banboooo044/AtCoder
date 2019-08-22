N,A,B,C = map(int,input().split(" "))
l = [ int(input()) for _ in range(N)]

def rec(idx,a,b,c):
    if idx == N:
        if a == 0 or b == 0 or c == 0:
            return float('inf')
        else:
            return abs(A-a) + abs(B-b) + abs(C-c)
    
    p1 = rec(idx+1,a,b,c)
    p2 = rec(idx+1,a+l[idx],b,c)
    if a != 0: p2 += 10 
    p3 = rec(idx+1,a,b+l[idx],c)
    if b != 0: p3 += 10
    p4 = rec(idx+1,a,b,c+l[idx])
    if c != 0: p4 += 10

    return min([p1,p2,p3,p4])

print(rec(0,0,0,0))
