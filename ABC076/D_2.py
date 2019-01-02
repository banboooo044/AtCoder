N = int(input())
ts = list(map(int, input().split()))
vs = list(map(int, input().split()))
 
sumT = sum(ts)
va = [min(i / 2, sumT - i / 2) for i in range(2 * sumT + 1)]
 
accT = 0
for t, v in zip(ts, vs):
    for i in range(accT, accT + 2 * t + 1):
        va[i] = min(va[i], v)
    accT += t * 2

print(va)
 
for i in range(len(va) - 1):
    if va[i + 1] - va[i] > 0.5:
        va[i + 1] = va[i] + 0.5
 
for i in range(len(va) - 1)[::-1]:
    if va[i] - va[i + 1] > 0.5:
        va[i] = va[i + 1] + 0.5
 
print(sum(va) / 2)
