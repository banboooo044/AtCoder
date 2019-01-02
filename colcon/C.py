A,B = map(int,input().split(" "))
odd = []
even = []
div_lis = [3,5,7,11,13,17,19,23,29,31]

divlis_move = []

if A % 2 == 1 :
	even = [ i for i in range(A+1,B+1,2)]
	odd = [ i for i in range(A,B+1,2)]
else:
	odd = [ i for i in range(A+1,B+1,2)]
	even = [ i for i in range(A,B+1,2)]

lo = len(odd)
le = len(even)
even_divlis = [[] for _ in range(le)]
odd_divlis = [[] for _ in range(lo)]

for i in range(lo):
	for div in div_lis:
		if odd[i] % div == 0:
			odd_divlis[i].append(div)

for i in range(le):
	for div in div_lis:
		if even[i] % div == 0:
			even_divlis[i].append(div)

ans = 0
count = 1
for ev in range(le):
	divlis_move = even_divlis[ev][:]
	for od in range(lo):
		flag = 0
		for num in odd_divlis[od]:
			if num in divlis_move:
				flag = 1
				break

		if flag == 0:
			count += 1
			divlis_move.extend(odd_divlis[od])

	print(count)
	ans += ((2**count) - count - 1)
	count = 1

print(ans + 1 + lo + le)



