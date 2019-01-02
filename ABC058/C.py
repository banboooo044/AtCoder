n = int(input())
dic = {}
S = input()
key_set = []
for c in S:
	if c in dic:
		dic[c] += 1
	else:
		dic[c] = 1
		key_set.append(c)



for i in range(n-1):
	dic_tmp = {}
	key_set_tmp = []
	S = input()
	for c in S:
		if c in dic_tmp:
			dic_tmp[c] += 1
		else:
			dic_tmp[c] = 1
			key_set_tmp.append(c)

	for key in set(key_set) & set(key_set_tmp):
		dic[key] = min(dic_tmp[key],dic[key])

	for key in set(key_set):
		if not key in key_set_tmp:
			dic.pop(key)
			key_set.remove(key)

ans = []
for key,value in dic.items():
	ans.append(key * value)

ans.sort()
print(''.join(ans))






	