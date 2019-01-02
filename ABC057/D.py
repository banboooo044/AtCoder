from scipy.misc import comb
import math
import copy

def nClr(n,l,r):
	ans = 0
	pat = 1
	if l == 0:
		ans += 1
		l += 1

	for i in range(l-1):
		pat *= ((n-i)/(i+1))

	for i in range(l-1,r):
		pat *= ((n-i)/(i+1))
		ans +=  pat

	return int(ans)

N,A,B =  map(int,input().split(" "))
v =  list(map(int,input().split(" ")))

v.sort(reverse=True)

mean =float(sum(v[0:A]))/float(A)
whole = {}

for i in range(A):
	if v[i] in whole:
		whole[v[i]] += 1
	else:
		whole[v[i]] = 1

ran_A = copy.deepcopy(whole)

for i in range(A,N):
	if v[i] in whole:
		whole[v[i]] += 1
	else:
		whole[v[i]] = 1


if len(ran_A) == 1:
	n = min(B,whole[v[0]])
	num = nClr(whole[v[0]],A,n)
	print(mean)
	print(num)
	exit(0)


num = 1
for key,val in ran_A.items():
	if ran_A[key] != whole[key]:
		num *= comb(whole[key],ran_A[key])


print(mean)
print(round(num))

