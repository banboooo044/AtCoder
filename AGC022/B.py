seq = [2,5]
mar = [5,2]
N = int(input())
sumval = 7
for i in range(2,N-1):
	seq.append(sumval)
	mar = list(map(lambda x: x+sumval,mar))
	mar.append(sumval)
	sumval += seq[-1]

val = sumval
while val <= 30000:
	flg = True
	for i in range(N-1):
		if ((val + mar[i]) % seq[i]) != 0:
			flg = False
			break

	if flg:
		seq.append(val)
		break
	else:
		val += sumval

for num in seq:
	print(num,end=' ')
print()