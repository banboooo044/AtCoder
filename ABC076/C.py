S = input()
T = input()

i = 0
l = len(T)


def search(i,j):
	if T[i:i+j] in S:
		return T[i:i+j]
	else:
		if i + j == l-1:
			return 0
		m = search(i+1,j) 

		if m == 0:
			return 0
		else:
			return m

def dec (m,S,T):
	S2 = list(S)
	S2


for j in range(l-1,-1,-1):
	m = search[0][j]
	if m != 0:
		



