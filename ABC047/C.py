S = input()
prev = S[0]
cnt = 1
for i in range(len(S)):
	if prev != S[i]:
		cnt += 1
		prev = S[i]

print(cnt - 1)
	