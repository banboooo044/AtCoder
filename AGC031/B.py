N = int(input())

if N % 2 == 1:
    print(N * (N-1) - (N // 2))
    for i in range(1,N+1):
        for j in range(i+1,N+1):
            if i + j != (N):
                print("{0} {1}".format(i,j))

else:
    print()