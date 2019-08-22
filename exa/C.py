N , Q = map(int,input().split(" "))
s = input()
L = s[0]
R = s[-1]
t,d = [0]*Q,[0]*Q
Llist = []
Rlist = []
for i in range(Q):
    t[i],d[i] = map(int,input().split(" "))
    if t[i] == L and d[i] == 'L':
        Llist.append(i)
    if t[i] == R and d[i] == 'R':
        Rlist.append(i)

for lidx in Llist:
    for 