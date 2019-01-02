def nPr (n,r):
	p = 1

	for i in range(n-r+1,n+1):
		p *= i
	
	return p

def count (n,D,L):
	p = 1

	a = nPr(n,D+L)

	print(a)

	for i in range(1,D+1):
		p *= i
	for j in range(1,L+1):
		p *= j

	return a / p


print(count(3,3,0))