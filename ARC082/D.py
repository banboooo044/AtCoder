N = int(input())
p = list(map(int,input().split(" ")))

i = 0
cou = 0
while i < N:
	if p[i] == i+1:
		cou += 1
		i += 2
	else:
		i += 1
print(cou)