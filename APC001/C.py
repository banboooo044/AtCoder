N = int(input())
ans = float('inf')
print(0)
s = input()
if s == "Male":
	pre = 1
elif s == "Female":
	pre = 0
else:
	ans = 0

if ans == 0:
	exit(0)

ran = [0,N-1]
for i in range(19):	
	n = (ran[1] - ran[0]) // 2
	print(ran[0] + n)
	s = input()
	if s == "Male":
		flg = 1
	elif s == "Female":
		flg = 0
	else:
		exit(0)

	if (pre + n) % 2 != flg:
		ran[1] = ran[0] + n - 1
	else:
		ran[0] = ran[0] + n + 1
		pre = (flg + 1) % 2