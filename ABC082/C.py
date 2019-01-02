N = int(input())
a = list(map(int,input().split(" ")))

dic = {}

for num in a:
	if num in dic:
		dic[num] += 1
	else:
		dic[num] = 1

ans = 0
for key,value in dic.items():
	if key > value:
		ans += value

	else:
		ans += (value - key)


print(ans)
