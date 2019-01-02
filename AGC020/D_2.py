def binary_search(a,b):
	"""str_Aで文字Aを使う回数を探索する"""
	l = 0
	r = a
	retval = (-1)
	while l <= r:
		mid = (l+r) // 2
		if mid % n == 0:
			used_b = (mid // n) -1
		else:
			used_b = mid // n 

		if (b - used_b) <= ((a-mid) * n):
			l = mid + 1
		else:
			r = mid - 1
			if (b - used_b) <= ((a-mid+1) * n):
				retval = max(mid,retval)

	return max(retval,mid)


Q = int(input())
for i in range(Q):
	a,b,c,d = map(int,input().split(" "))
	max_ab = max(a,b)
	min_ab = min(a,b)

	if max_ab % (min_ab+1) == 0:
		n = max_ab // (min_ab+1)
	else:
		n = ( max_ab // (min_ab+1)) + 1
	
	a_count = a
	b_count = b - n
	A_str = ""
	B_str = ('B'* n)
	while a_count > 0:
		A_str += ('A' * n) 
		A_str += 'B'
		a_count -= n

	while b_count > 0:
		B_str += 'A'
		B_str += ('B'* n)
		b_count -= n

	N_a = binary_search(a,b)
	if (N_a) % n == 0 and N_a != 0:
		A_l = (N_a + (N_a // n) - 1)
	else:
		A_l = (N_a + (N_a // n))

	len_B = len(B_str)
	B_l = a + b - A_l

	ans = A_str[0:A_l] + B_str[len_B-B_l:len_B]
	#print(ans)
	print(ans[c-1:d])




