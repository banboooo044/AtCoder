n,L,R = map(int,input().split(" "))
a = list(map(int,input().split(" ")))

for i in range(n):
	if a[i] <= L:
		print(L,end=" ")
	elif a[i] <= R:
		print(a[i],end=" ")
	else:
		print(R,end=" ")

print()