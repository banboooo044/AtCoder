#! usr/bin/env python3
#C:


S = list(input())


i = 0
j = len(S) - 1

insert = 0

while True:
	if i >= j:
		break

	elif S[i] == S[j]:
		i += 1
		j -= 1

	elif S[i] == 'x':
		i += 1
		insert += 1

	elif S[j] == 'x':
		j -= 1
		insert += 1

	else:
		insert = -1
		break

print(insert)

