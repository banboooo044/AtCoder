N,H = map(int,input().split(" "))
a = [0] * N
b = [0] * N
for i in range(N):
	a[i],b[i] =  map(int,input().split(" "))

max_a = max(a)
b_2 = [i for i in b if i > max_a]

b_2.sort(reverse=True)
l = len(b_2)

for i in range(l):
	H -= b_2[i]
	if H <= 0:
		print(i+1)
		exit(0)

ans = l
if H  % max_a == 0:
	ans += (H//max_a)
else:
	ans += ((H//max_a)+1)

print(ans)



