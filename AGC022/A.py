s = input()
s2 = list(s)
ch = [chr(i) for i in range(97, 97+26)]
flg = 0
for k in ch:
	if not k in s2:
		s += k
		flg = 1
		break

if flg == 1:
	print(s)
	exit(0)
else:
	l = len(s)
	ans = ''
	for i in range(l-1,0,-1):
		for k in ch:
			if k <= s[i]:
				continue
			elif not k in s2[:i]:
				ans = s[:i] + k
				print(ans)
				exit(0)

	if s[0] == 'z':
		print(-1)
	else:
		print(chr(ord(s[0])+1))
