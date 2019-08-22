N = int(input())
a = list(map(int,input().split(" ")))
mod = 10**9 + 7

allxor = 0
tmpxor = 0
idx = [ ]
value = { }
for i in range(N):
    allxor ^= a[i]
    tmpxor ^= a[i]
    if not tmpxor in value:
        value[tmpxor] = 1
    else:
        value[tmpxor] += 2

    if tmpxor == 0:
        idx.append(i)

if allxor != 0:
    cnt = 0
    tmpxor = 0
    for i in range(N):
        tmpxor ^= a[i]
        if tmpxor == allxor:
            cnt += 1
            tmpxor = 0
    
    print(pow(2,cnt,mod))
    exit(0)

l = len(idx)
ans = pow(2, l-1, mod)

for key,value in value.items():
    if key == 0:
        continue
    if value == 1:
        ans += 1
    else:
        ans += (value%3) * ( pow(2, value//3) - 1) + 1
print(ans)



