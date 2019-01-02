N = int(input())
s = input()

pat1 = [-1] * N
pat2 = [-1] * N
pat3 = [-1] * N
pat4 = [-1] * N

pat1[1] = pat2[1] = 1
pat3[1] = pat4[1] = 0

if s[1] == 'o':
	pat1[0] = pat1[2] = 0
	pat2[0] = pat2[2] = 1
	pat3[0] = pat4[2] = 0
	pat3[2] = pat4[0] = 1

else:
	pat1[0] = pat2[2] = 0
	pat2[0] = pat1[2] = 1
	pat3[0] = pat3[2] = 0
	pat4[2] = pat4[0] = 1


#print([pat1,pat2,pat3,pat4])

for i in range(2,N-1):
	for lis in [pat1,pat2,pat3,pat4]:
		if lis[i] == 1:
			if s[i] == 'o':
				lis[i+1] = lis[i-1]

			else:
				lis[i+1] = (lis[i-1] + 1)%2
		else:
			if s[i] == 'x':
				lis[i+1] = lis[i-1]

			else:
				lis[i+1] = (lis[i-1] + 1)%2

#print([pat1,pat2,pat3,pat4])

def ok1(List):
	global s
	if List[N-1] == 1:
		if s[N-1] == 'o':
			return List[N-2] == List[0]
		else:
			return List[N-2] != List[0]

	else:
		if s[N-1] == 'x':
			return List[N-2] == List[0]
		else:
			return List[N-2] != List[0]

def ok2(List):
	global s
	if List[0] == 1:
		if s[0] == 'o':
			return List[N-1] == List[1]
		else:
			return List[N-1] != List[1]

	else:
		if s[0] == 'x':
			return List[N-1] == List[1]
		else:
			return List[N-1] != List[1]





flg = []
for lis in [pat1,pat2,pat3,pat4]:
	if ok1(lis) and ok2(lis):
		flg = lis
		break
	
#print(flg)
ans = ""
if flg != []:
	for num in flg:
		if num ==  0:
			ans += 'W'
		else:
			ans += 'S'

	print(ans)

else:
	print(-1)




