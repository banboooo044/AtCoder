s = input()
K = int(input())
l = len(s)
dic = {}
for i in range(l):
	if not s[i] in dic:
		dic[s[i]] = []
	for j in range(1,6):
		if i + j > (l):
			break
		else:
			dic[s[i]].append(s[i:i+j])

lst = list(dic.keys())
lst.sort()
for c in lst:
	dic[c] = sorted(set(dic[c]))
	l = len(dic[c])
	if K > l:
		K -= l
	else:
		print(dic[c][K-1])
		exit(0)