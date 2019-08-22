N,A,B = map(int,input().split(" "))

if A > B:
    print(0)
    exit(0)
if N == 1:
    if A ==  B:
        print(1)
    else:
        print(0)
    exit(0)
if N == 2:
    print(1)
    exit(0)

print((N-2)*(B-A)+1)