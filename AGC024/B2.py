N = int(input())
a = [0]*N
dic = {}

def swap(a,b):
	tmp = a
	a = b
	b = tmp

cnt = 0
for i in range(N):
	a[i] = int(input())
	dic[a[i]] = i

if N % 2 == 1:
	m = (N//2)+1
	if dic[m+1] < dic[m]:
		swap(a[N-1],a[dic[m+1]])
		swap(dic[m+1],dic[a[dic[m+1]]])
		cnt += 1

	if dic[m-1] > dic[m]:
		swap(a[0],a[dic[m-1]])
		swap(dic[m-1],dic[a[dic[m-1]]])
		cnt += 1

	l = m-1
	r = m+1
else:
	l = N//2
	r = (N//2)+1
i = 0
while (r+i) < N:
	if dic[r+i] < dic[r]:
		swap(a[N-1],a[dic[r+i]])
		swap(dic[r+i],dic[a[dic[r+i]]])
		cnt += 1
	if dic[l-i] < dic[l]:
		swap(a[0],a[dic[r-i]])
		swap(dic[r-i],dic[a[dic[r-i]]])
		cnt += 1

	i += 1

print(cnt)



