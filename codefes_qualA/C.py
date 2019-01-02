def fourcount(List):

	num = 0
	tmp = 1
	l = len(List)

	for i in range(1,l):

		if (List[i-1] == List[i]) and (tmp < 4):
			tmp += 1

		elif tmp == 4:
			num += 1
			tmp = 1

		else:
			tmp = 1

	if tmp == 4:
		num += 1
		
	return num
		

def twocount(List):

	num = 0
	tmp = 1
	l = len(List)

	for i in range(1,l):

		if (List[i-1] == List[i]) and (tmp < 2):
			tmp += 1

		elif tmp == 2:
			num += 1
			tmp = 1

		else:
			tmp = 1

	if tmp == 2:
		num += 1
		
	return num

def decision(H,W,num4,num2):

	if H == 1:
		if (W % 2 == 0) and (num2 == W/2):
			print("Yes")
		elif (W % 2 == 1) and (num2 == (W-1)/2):
			print("Yes")
		else:
			print("No")

	elif W == 1:
		if (H % 2 == 0) and (num2 == H/2):
			print("Yes")
		elif (H % 2 == 1) and (num2 == (H-1)/2):
			print("Yes")
		else:
			print("No")

	elif H == 0 or W == 0:
		print("Yes")

	elif H > W:
		if (H % 2 == 0) and (H / 2 <= num4):
			same = H/2
			decision(H,W-2,num4-same,num2-same*2)
		elif (H % 2 == 1) and ((H-1) / 2 <= num4 ) and (num2-(H-1) >= 1):
			same =  (H-1) /2
			decision(H,W-2,num4-same,num2-same*2-1)
		else:
			print("No")

	elif W > H:
		if (W % 2 == 0) and (W / 2 <= num4):
			same= W/2
			decision(H-2,W,num4-same,num2-same*2)
		elif (W % 2 == 1) and ((W-1) / 2 <= num4) and (num2-(W-1) >= 1):
			same =  (W-1) /2
			decision(H-2,W,num4-same,num2-same*2-1)
		else:
			print("No")

	elif W == H:
		if (H % 2 == 0) and (H - 1) <= num4 :
			same = H-1
			decision(H-2,W-2,num4-same,num2-same*2)
		elif (H % 2 == 1) and (H - 2) <= num4 and (num2-2*(H-2) >= 2):
			same = H-2
			decision(H-2,W-2,num4-same,num2-same*2-2)
		else :
			print("No")



H,W = map(int,input().split(" "))
a = []
b = []

for i in range(H):
	a = list(input())
	a = a[0:W]
	for string in a:
		b.append(string)

b.sort()

num4 = fourcount(b)
num2 = twocount(b) 

decision(H,W,num4,num2)

			











