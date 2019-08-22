L, R = map(int, input().split(" "))
mod = 10**9 + 7

n = 1
i = 0
ln, rn = -1, -1
while True:
    if ln == -1 and (n - 1) >= L:
        ln = i - 1

    if rn == -1 and (n - 1) >= R:
        rn = i
        break
    n *= 2
    i += 1

print(ln, rn)
ans = (pow(rn, 3, mod) - pow(ln, 3, mod) + mod) % mod
print(ans)
ls = 2**ln
for i in range(ls, L):
    for j in range(i, L):
        if (j % i) == (j ^ i):
            ans -= 1
rd = 2**rn
for i in range(R + 1, rd):
    for j in range(i, rd):
        if (j % i) == (j ^ i):
            ans -= 1

print((ans + mod) % mod)