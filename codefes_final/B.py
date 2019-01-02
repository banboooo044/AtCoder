# B問題
S = input()
l = len(S)
var = 0
var_str = {}

for ch in S:
	if not ch in var_str:
		var_str[ch] = 1
		var += 1
	else:
		var_str[ch] += 1

if l % 2 == 0:
	if max(var_str.values()) > (l // 2) :
		print("NO")
	else:
		print("YES")

else:
	if max(var_str.values()) > ((l+1) // 2):
		print("NO")
	else:
		if len(var_str) <= 2:
			print("NO")
		else:
			print("YES")