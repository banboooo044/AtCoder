# C問題
def solve(List1,List2):
	maxval = -1
	for i in List1:
		dif = abs(i-List2[0])
		if dif > 12:
			dif = 24 - dif

		if maxval < dif:
			maxval = dif

	return maxval

N = int(input())
D = list(map(int,input().split(" ")))

D = list(map(lambda x:[x,(24-x)],D))

D.append([0,24])

table = []
for i in range(N+1):
	for j in range(i+1,N+1):
		table.append(solve(D[i],D[j])) 

print(min(table))

