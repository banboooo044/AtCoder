s = input()
x,y = map(int,input().split(" "))

#dir:0 右 1 上  左 3 下

ans = [(0,0,0)]

for ch in s:
	if ch == "T":
		tmp = []
		for lis in ans:
			tmp.append((lis[0],lis[1],(lis[2]+1)%4))
			tmp.append((lis[0],lis[1],(lis[2]-1)%4))

		ans = list(set(tmp))

	else:
		for i in range(len(ans)):
			if (ans[i][2] % 4 == 0):
				ans[i] = (ans[i][0]+1,ans[i][1],ans[i][2])
			elif (ans[i][2] % 4 == 1):
				ans[i] = (ans[i][0],ans[i][1]+1,ans[i][2])
			elif (ans[i][2] % 4 == 2):
				ans[i] = (ans[i][0]-1,ans[i][1],ans[i][2])
			else:
				ans[i] = (ans[i][0],ans[i][1]-1,ans[i][2])


for lis in ans:
	if (lis[0] == x) and (lis[1] == y):
		print("Yes")
		exit(0)

print("No")
		