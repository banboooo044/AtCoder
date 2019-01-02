n = input()

n1 = int(n[0])
n2 = int(n[1])
n3 = int(n[2])
n4 = int(n[3])

for op2 in [n2,-n2]:
	for op3 in [n3,-n3]:
		for op4 in [n4,-n4]:			
			if n1+op2+op3+op4 == 7:
				a = [op2,op3,op4]
				break

ans = str(n1)
for i in a:
	if i >= 0:
		ans += (('+') + str(i))
	else:
		ans += str(i)

ans += '=7'
print(ans)
