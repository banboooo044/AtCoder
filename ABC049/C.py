S = input()
word5 = ['dream','erase']
word6 = ['dreamer',]

i = len(S)

while True:
	if i - 5 < 0:
		break

	if S[i-5:i] in word5:
		i -= 5

	elif i - 6 >= 0 and S[i-6:i] == 'eraser':
		i -= 6

	elif i - 7 >= 0 and S[i-7:i] == 'dreamer':
		i -= 7

	else:
		break

if i == 0:
	print("YES")
else:
	print("NO")
