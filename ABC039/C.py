s = input()
l = len(s)
flg = "WWBWBWW"
sound = ['Si','La','So','Fa','Mi','Re','Do']
cnt = 0
for i in range(l):
	if s[i] == 'W':
		cnt += 1

	if s[i:i+7] == flg:
		cnt -= 1
		break

print(sound[(cnt % 7)])

