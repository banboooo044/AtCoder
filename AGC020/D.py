Q = int(input())
ans = []
for i in range(Q):
	a,b,c,d = map(int,input().split(" "))
	if a >= b:
		if (a % (b+1)) == 0:
			n = a // (b+1)
		else:
			n = (a // (b+1)) + 1

		margin = n * (b+1) - a
		n_num = (b) - (margin // (n-1))
		num = [1] * (margin // (n-1))
		num.append(n - (margin % (n-1)))
		num.extend([n]*n_num)

		ans_str = ""
		

	else:
		if (b % (a+1)) == 0:
			n = b // (a+1)
		else:
			n = (b // (a+1)) + 1


		margin = n * (a+1) - b
		n_num = (a) - (margin // (n-1))
		num = [1] * (margin // (n-1))
		num.append(n - (margin % (n-1)))
		num.extend([n]*n_num)
		
		ans_str = ""
		while a > 0 or b > 0:
			if b == 0:
				ans_str += (('A'))
				a -= 1

			elif n * (a+1) >= b and n * (a) < b:
				ans_str += (('B') * n )
				ans_str += (('A'))
				b -= n
				a -= 1

			else:
				n -= 1

		ans_str = ans_str[::-1]

	ans.append(ans_str)#[c-1:d])

for i in ans:
	print(i)

