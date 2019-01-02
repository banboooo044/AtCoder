S = input()
l = len(S)

i = 1
cnt = 0
tmp = (-1)
while i < l:
	if S[i] == '*':
		if tmp == (-1):
			tmp = int(S[i-1])*int(S[i+1])
		else:
			tmp *= int(S[i+1])

	elif S[i] == '+':
		if tmp == (-1):
			if S[i-1] != '0':
				cnt += 1

		elif tmp != 0:
			cnt += 1
		tmp = (-1)

	i += 2

if tmp == (-1) and S[l-1] == '0':
	pass
elif tmp != 0:
	cnt += 1

print(cnt)


