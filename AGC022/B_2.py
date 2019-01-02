N = int(input())
l = N // 4
ans = []

if N == 3:
	print("2 5 63")
	exit(0)
elif N == 4:
	print("2 5 20 63")
	exit(0)
elif N == 5:
	print("6 8 9 10 15")
	exit(0)
elif N == 6:
	print("6 8 9 10 12 15")
	exit(0)

for i in range(l):
	ans.extend([6*i+2,6*i+3,6*i+4,6*i+6])

add = [6*(l)+2,6*(l)+3,6*(l)+4,6*(l+1)]
ans.extend(add[:N%4])
s = sum(ans)
flg = s % 6

if flg == 1:
	cor = 2 - (ans[-1]%6)
	if cor <= 0:
		cor += 6
	ans[1] = ans[-1] + cor

elif flg == 2:
	ans[0] = ans[-1] - (ans[-1]%6) + 6
elif flg == 3:
	ans[1] = ans[-1] - (ans[-1]%6) + 6
elif flg == 4:
	ans[2] = ans[-1] - (ans[-1]%6) + 6
elif flg == 5:
	cor = 4 - (ans[-1]%6)
	if cor <= 0:
		cor += 6
	ans[1] = ans[-1] + cor

print(*ans,end=' ')
