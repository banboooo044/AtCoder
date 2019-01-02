s = input()
count = 0
next_str = s
now_str = ''
while next_str != '' and next_str != now_str:
	count += 1
	i = 0
	now_str = next_str
	next_str = ''
	l = len(now_str)

	while l > i:
		if i == (l-1):
			next_str += now_str[i]
			i += 1
		elif now_str[i] == '2' and now_str[i+1] == '5':
			i += 2
		else:
			next_str += now_str[i]
			i += 1

if next_str != '':
	print(-1)
else:
	print(count)
