N = int(input())
s = input()

r = 0
for i in s:
    if i == 'R':
        r += 1

if r > N -r:
    print("Yes")
else:
    print("No")