X = int(input())
pos = [0]

for i in range(1,X+1):
	tmp = []
	for j in pos:
		tmp.append(j + i)
		if j + i ==  X:
			print(i)
			exit(0)

	pos.extend(tmp)
	pos = list(set(pos))
