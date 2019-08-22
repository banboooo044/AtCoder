N ,K = map(int,input().split(" "))
if N % 2 == 1:
    if K <= ((N - 1) // 2) + 1:
        print("YES")
    else:
        print("NO")

else:
    if K <= ((N - 2) // 2) + 1:
        print("YES")
    else:
        print("NO")