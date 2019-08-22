N = int(input())
b = list(map(int,input().split(" ")))
used = [0] * N
n = N
ans = []
for i in range(N):
    index = n
    flg = True
    for j in range(N-1,-1,-1):
        if used[j] == 0:
            if b[j] == index:
                used[j] = 1
                ans.append(b[j])
                flg = False
                break
            else:
                index -= 1
    if flg:
        print("-1")
        exit(0)
    n -= 1


print(*ans[::-1])
