N,H = map(int,input().split(" "))
A,B,C,D,E = map(int,input().split(" "))

need = (N * E - H) + 1
B += E
D += E
money = float('inf')
#print(need)
for i in range(N+1):
	if ((need - B*i) % D) != 0:
		j = (((need - B*i)//D)+1)
	else:
		j = (need-B*i)//D

	j = max(j,0)
	if i + j > N:
		continue
	#print(i)
	#print(j)
	#print(B*i+D*j)
	#print(A*i+C*j)
	#print()
	money = min(money,A*i+C*j)

print(money)