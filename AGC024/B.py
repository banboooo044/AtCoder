N = int(input())
a = [0]*N
cnt = 0
dic = {}
for i in range(N):
	a[i] = int(input())
	dic[a[i]] = i

ans = 1
cnt = 1
for num in range(1,N):
	if dic[num] < dic[num+1]:
		cnt += 1
	else:
		ans = max(cnt,ans)
		cnt = 1


ans = max(cnt,ans)
print(N-ans)


