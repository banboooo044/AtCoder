K,A,B = map(int,input().split(" "))

if (1+K) <= A:
    print(1+K)
    exit(0)

if B - A <= 2:
    print(1+K)
    exit(0)

K -= (A-1)
ans = A
ans += (B-A) * (K // 2)
if K % 2 == 1:
    ans += 1
print(ans)
