N = int(input())
A = list(map(int,input().split(" ")))
B = list(map(int,input().split(" ")))

sa = sum(A)
sb = sum(B)
if sa < sb:
    print("-1")
    exit(0)

A_ = [ a-b for a,b in zip(A,B) ]
A_.sort()

l = 0
r = N-1

ans = 0

used = [ False for _ in range(N) ]
while True:
    if A_[l] >= 0:
        break
    if A_[r] >= (-A_[l]):
        A_[r] += A_[l]
        used[r] = True
        used[l] = True
        l += 1
    
    else:
        A_[l] += A_[r]
        used[r] = True
        used[l] = True
        r -= 1

print(used.count(True))


