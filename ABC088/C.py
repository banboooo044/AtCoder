c1 = list(map(int,input().split(" ")))
c2 = list(map(int,input().split(" ")))
c3 = list(map(int,input().split(" ")))

for i in range(2):
	if c1[i+1] - c1[i] == c2[i+1] - c2[i] == c3[i+1] - c3[i]:
		flg = True
	else:
		flg = False

if flg == False:
	print("No")
	exit(0)

if c2[0] - c1[0] == c2[1] - c1[1] == c2[2] - c1[2] and c3[0] - c2[0] == c3[1] - c2[1] == c3[2] - c2[2]:
	print("Yes")
else:
	print("No")

