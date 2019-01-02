N,Y = map(int,input().split(" "))


for i in range(N,-1,-1):
	for j in range(N-i,-1,-1):
			num = (10000*i+5000*j+1000*(N-i-j))
			if num == Y:
				print(str(i) + " " + str(j) + " " + str(N-i-j))
				exit(0)

print("-1 -1 -1")