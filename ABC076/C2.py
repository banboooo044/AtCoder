S = input()
T = input()

ans = []
sl = len(S)
tl = len(T)
for i in range(sl-tl+1):
	if S[i] == '?' or S[i] == T[0]:
		flg = True
		for j in range(1,tl):
			if S[i+j] != '?' and S[i+j] != T[j]:
				flg = False
				break

		if flg:
			s = S[:i] + T + S[i+tl:]
			ans.append(s.replace('?','a'))

if ans == []:
	print("UNRESTORABLE")
	exit(0)

ans.sort()
print(ans[0])
