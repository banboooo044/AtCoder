S = input()
l = len(S)
ans = 100000000
count = 1
for i in range(l-1):
	if S[i+1] != S[i]:
		tmp = max([i+1,l-i-1])
		ans = min([ans,tmp])

if ans == 100000000:
	ans = l
print(ans)

