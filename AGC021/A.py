s = input()
s_n = int(s)
dig = len(s)

if dig == 1:
	cnt = 0
	for i in range(len(s)):
		cnt += int(s[i])
	print(cnt)
	exit(0)

flg = 1
for i in range(1,len(s)):
	if s[i] != '9':
		flg = 0
		break

if flg == 1:
	cnt = 0
	for i in range(len(s)):
		cnt += int(s[i])
	print(cnt)
	exit(0)

if s[0] == '1':
	print(9*(dig-1))
else:
	print(9*(dig-1) + int(s[0]) - 1)

