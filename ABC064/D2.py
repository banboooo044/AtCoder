N = int(input())
S = input()

cnt = 0
left = 0
for i in range(N):
	if S[i] == '(':
		cnt += 1
	else:
		if cnt == 0:
			left += 1
		else:
			cnt -= 1

ans = ("("*left) + S + ")"*cnt
print(ans)
