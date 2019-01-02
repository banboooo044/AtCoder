s = input()
w = int(input())
ans = ""
for i in range(0,len(s),w):
	ans += s[i]

print(ans)