N,Q = map(int,input().split(" "))
S = input()
a = [0] *  N
acc = [0] * N
for i in range(N-1):
    if S[i] == 'A' and S[i+1] == 'C':
        a[i] = 1
        acc[i] += a[i]
    acc[i+1] = acc[i]

acc[N-1] = acc[N-2]
for i in range(Q):
    l,r = map(int,input().split(" "))
    if l > 1:
        ans = acc[r-1] - acc[l-2]
    else:
        ans = acc[r-1]
    if a[r-1] == 1:
        ans -= 1
    
    print(ans)