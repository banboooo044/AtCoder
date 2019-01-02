N = int(input())
D = [0]*N
for i in range(N):
    D[i] = [int(x) for x in input().split()]

mval = [0]*(N*N+1)

for i in range(1,N+1):
    tmp = [[sum(x[j:j+i]) for j in range(N+1-i)] for x in D]
    ttmp = list(zip(*tmp))
    for k in range(1,N+1):
        a = max([max([sum(x[j:j+k]) for j in range(N+1-k)]) for x in ttmp])
        if mval[k*i] < a:
            mval[k*i] = a

print(mval)
print(D)
Q = int(input())
P = [0]*Q

for i in range(Q):
    P[i] = int(input())
for x in P:
    print(max(mval[:x+1]))