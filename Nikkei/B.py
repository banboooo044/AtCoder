N = int(input())
A = input()
B = input()
C = input()

cnt =0
for i in range(N):
    if A[i] == B[i] == C[i]:
        pass
    elif A[i] == B[i]:
        cnt += 1
    elif B[i] ==  C[i]:
        cnt += 1
    elif C[i] == A[i]:
        cnt += 1
    
    else:
        cnt += 2
    

print(cnt)