N = int(input())
ans = 0
A,B,AB = 0,0,0
for i in range(N):
    s = input()
    ans += s.count('AB')
    if s[0] == 'B' and s[-1] ==  'A':
        AB += 1
    elif s[0] == 'B':
        B += 1
    elif s[-1] == 'A':
        A += 1


add =  0

if AB != 0:
    add += (AB - 1)
    if A >= 1:
        A -= 1
        add += 1
    if B >= 1:
        B -= 1
        add += 1
add += min(A,B)

print(min(add,N-1) + ans)