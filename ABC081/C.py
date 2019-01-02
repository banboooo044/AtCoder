N , K = map(int,input().split(" "))
A = list(map(int,input().split(" ")))

ans = 0
num = {}
key = 0
for i in A:
	if i in num:
		num[i] += 1
	else:
		num[i] = 1
		key += 1

if key - K <= 0:
	print("0")
	exit(0)

num2 = sorted(num.items(), key=lambda x:x[1])
for i in range(key-K):
	ans += num2[i][1]

print(ans)




