S_raw = input()
T_raw = input()

S = list(S_raw)
T = list(T_raw)

i = 0
j = 0

j_list = []
S_list = []

lt = len(T)
ls = len(S)

while True:
	if (j >= ls) or (i >= lt):
		if i < lt  :
			if j_list == []:
				print("UNRESTORABLE")
				exit(0)
			else:
				break
		elif j < ls:
			j_list.append(j)
			i = 0
			j = j - lt + 1

		else:
			j_list.append(j)
			break

	if T[i] == S[j]:
		i += 1
		j += 1
	elif S[j] == '?':
		i += 1
		j += 1
	else:
		j -= (i - 1)
		i = 0

for k in j_list:
	M = S[:]
	for i,c in zip(range(k-lt,k),T):
		M[i] = c

	S_tmp = ''

	for i in range(ls):
		if M[i] == '?':
			S_tmp += 'a'
		else:
			S_tmp += M[i]

	S_list.append(S_tmp)

S_list.sort()
print(S_list[0])