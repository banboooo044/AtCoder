def gcd (a,b):
	if a < b:
		a,b = b,a
	return a if b == 0 else gcd(b,a%b)
T = int(input())
for i in range(T):
	A,B,C,D = map(int,input().split(" "))
	if A < B:
		print("No")
		continue

	if D < B:
		print("No")
		continue

	if A > C:
		init = C + ((A - C) % B)
		if init != C:
			init -= B
		if init < 0:
			print("No")
			continue
	else:
		init = A

	if C >= (B-1):
		print("Yes")
		continue

	dif = (D - B)
	if dif == 0:
		print("Yes")
		continue
	i = C - ((C - init) % dif)
	m = B % dif

	k = 0
	flg = False
	while m * k < dif:
		if i + dif - m*k < B:
			print("No")
			flg = True
			break
		k += 1
	if not flg:
		print("Yes")


