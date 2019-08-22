from bisect import bisect_left
A , B, Q = map(int,input().split(" "))
s = [0] * A
t = [0] * B
x = [0] * Q
for i in range(A):
    s[i] = int(input())
for i in range(B):
    t[i] = int(input())

for i in range(Q):
    x[i] = int(input())
    shrine1 = bisect_left(s,x[i])
    shrine2 = shrine1 - 1
    temple1 = bisect_left(t,x[i])
    temple2 = temple1 - 1
    a = float('inf')
    if shrine1 == len(s):
        s1,s2 = (x[i] - s[-1]),float('inf')
    elif shrine1 == 0:
        s1,s2 = float('inf'),(s[0] - x[i])
    else:
        s1,s2 = x[i] - s[shrine2],s[shrine1] - x[i]

    if temple1 == len(t):
        t1,t2 = (x[i] - t[-1]),float('inf')

    elif temple1 == 0:
        t1,t2 = float('inf'),(t[0] - x[i])
    else:
        t1,t2 = x[i] - t[temple2],t[temple1] - x[i]
    print(min([ max(s2,t2) , max(t1,s1) , min(s1,t2)*2+max(s1,t2), min(s2,t1)*2+max(s2,t1) ]))
    
