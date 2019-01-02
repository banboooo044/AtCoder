from itertools import product
N = int(input())
for tup in product('abc',repeat=N):
	print("".join(tup))