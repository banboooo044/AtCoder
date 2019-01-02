N = int(input())
a = list(map(int,input().split(" ")))

a.sort(reverse=True)

al = 0
bo = 0

if N % 2 == 1:
	N -= 1
	al += a[-1]

for i in range(0,N,2):
	al += a[i]
	bo += a[i+1]

print(al-bo)

