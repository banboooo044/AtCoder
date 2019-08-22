N, M =  map(int,input().split(" "))
A = list(map(int,input().split(" ")))
A.sort()
BC = []
for i in range(M):
    B,C = map(int,input().split(" "))
    BC.append((B,C))

BC.sort(reverse=True,key=lambda x: x[1])

i = 0
flg = True
for B,C in BC:
    for j in range(B):
        if C > A[i]:
            A[i] = C
            i += 1
        else:
            flg = False
            break

        if i == N:
            break
    if i == N or (not flg):
        break

print(sum(A))

