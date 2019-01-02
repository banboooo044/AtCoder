N = int(input())
a = list(map(int,input().split(" ")))

dic = {i : 0 for i in range(9)}
for i in range(N):
	if (a[i] // 400) > 7:
		dic[8] += 1
	else:
		dic[(a[i] // 400)] += 1

minv = 0
for i in range(8):
	if dic[i] >= 1:
		minv += 1

print(max(minv,1),minv+dic[8])