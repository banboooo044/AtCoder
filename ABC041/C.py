N = int(input())
a = list(map(int,input().split(" ")))
b = [(i,j) for j,i in zip(range(1,N+1),a) ]

b.sort(reverse=True)
for i,j in b:
	print(j)