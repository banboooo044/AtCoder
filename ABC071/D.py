N = int(input())
S1 = input()
S2 = input()
mod = 1000000007

if N == 1:
	print(3)
	exit(0)

if S1[0] == S1[1]:
	i = 2
	ans = 6
	prev_flag = 2
else:
	i = 1
	ans = 3
	prev_flag = 1

while i < (N-1):
	if S1[i] == S1[i+1]:
		i += 1
		if prev_flag == 2:
			ans *= 3
		else:
			ans *= 2

		prev_flag = 2

	else:
		if prev_flag == 1:
			ans *= 2

		prev_flag = 1

	i += 1

if i == (N-1) and prev_flag == 1:
	ans *= 2

print(ans%mod)




