from itertools import combinations
N = int(input())
march = ['M','A','R','C','H']
dic = {}
for i in range(N):
	s = input()
	if s[0] in march:
		if s[0] in dic:
			dic[s[0]] += 1
		else:
			dic[s[0]] = 1

ans = 0
if len(dic.keys()) < 3:
	print(0)
else:
	for tup in combinations(dic.values(),3):
		#print(tup)
		ans += (tup[0] * tup[1] * tup[2])

	print(ans)




	