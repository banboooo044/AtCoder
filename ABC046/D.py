s = input()
dic = { 'g' : 0 ,'p' : 0 }
for ch in s:
	if ch == 'g':
		dic['g'] += 1
	else:
		dic['p'] += 1

print((dic['g'] - dic['p']) // 2)