L = int(input())
A = [0] * L
odd = [0] * L
even = [0] * L
for i in range(L):
    A[i] = int(input())
    if A[i] % 2 == 0:
        odd[i] = 1
    elif A[i] == 0:
        odd[i] = 2
        even[i] = 1
    else:
        even[i] = 1

for i in range(L-1):
    odd[i+1] += odd[i]
    even[i+1] += even[i]

print(odd,even)
l,r = 0,0
prev = float('inf')
ans = float('inf')
while r >= l and r < L:
    print(l,r)
    if r > 0:
        R = (odd[-1] - odd[r-1]) 
    else:
        R = odd[-1]
    M = (even[r-1]) if r > 0 else 0
    if l > 0:
        M -= even[l-1]
        ll = odd[l-1]
    else:
        ll = 0
    if l == 0 and r == 3:
        print(R,M,ll)
    cur = R + M + ll
    ans = min(ans,cur)
    if prev > cur and r < L:
        r += 1
        prev = cur
    else:
        l += 1

print(ans)
    
    