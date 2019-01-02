inf = 10**18
A,B,C,K = map(int,input().split(" "))
if K % 2 == 1:
	if (B-A) > inf:
		print("Unfair")
	else:
		print(B-A)
else:
	if (A-B) > inf:
		print("Unfair")
	else:
		print(A-B)