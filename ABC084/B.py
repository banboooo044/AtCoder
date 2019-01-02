A,B = map(int,input().split(" "))
S = input()

for i in range(A+B+1):
	if i == A:
		if S[i] != '-':
			print("No")
			exit(0)

	else:
		if not (S[i].isdigit()):
			print("No")
			exit(0)

print("Yes")


