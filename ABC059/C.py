N = int(input())
a = list(map(int,input().split(" ")))


def is_positive(sumval,modify):
	if sumval <= 0:
		modify += abs(sumval - 1)
		sumval = 1

	return sumval,modify

def is_negative(sumval,modify):
	if sumval >= 0:
		modify += abs(sumval + 1)
		sumval = (-1)


	return sumval,modify

pos_sum,pos_modi = is_negative(a[0],0)
neg_sum,neg_modi = is_positive(a[0],0)

for i in range(1,N):
	tmp_sum,tmp_modi = is_positive(pos_sum + a[i],pos_modi)
	pos_sum,pos_modi = is_negative(neg_sum + a[i],neg_modi)
	neg_sum = tmp_sum
	neg_modi = tmp_modi

print(min(pos_modi,neg_modi))
