N = int(input())
S = list(input())
S_2 = S[:]
prev = 0
cnt = 0
new_str = []
for i in range(len(S)):
	if S[i] == '(':
		cnt += 1
	else:
		cnt -= 1

	if cnt < 0:
		S_2.insert(0,'(')
		cnt += 1


if cnt > 0:
	for i in range(cnt):
		S_2.append(')')

print(''.join(S_2))