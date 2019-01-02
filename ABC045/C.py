s = input()
l = len(s)
val = []
for i in range(2 ** (l-1)):
	div = [0]
	for j in range((l-1)):
		if (i >> j) & 1:
			div.append(j+1)
	v = 0
	for d in range(len(div)-1):
		v += int(s[div[d]:div[d+1]])
	v += int(s[div[-1]:])

	val.append(v)

print(sum(val))
