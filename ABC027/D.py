s = input()
arr = []
move = []
l = len(s)

flg = False
cnt = 0
cntarr = 0
for i in range(l):
	if s[i] == 'M':
		if flg:
			move.append(cnt)
		cnt = 0
		cntarr += 1
		flg = False

	else:
		flg = True
		arr.append(cntarr)
		cntarr = 0
		if s[i] == '+':
			cnt += 1
		else:
			cnt -= 1

if cntarr != 0:
	arr.append(cntarr)
if cnt != 0:
	move.append(cnt)
print(arr)
print(move)

if s[0] == 'M':
	
lm = len(move)