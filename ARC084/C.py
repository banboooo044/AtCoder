#C問題

N = int(input())
A = list(map(int,input().split(" ")))
B = list(map(int,input().split(" ")))
C = list(map(int,input().split(" ")))

A.sort()
B.sort()
C.sort()




ans = 0
tmp_ans = 0
tmp = 0
for i in range(N):

	if 0 < i:
		if A[i-1] == A[i]:
			ans += tmp_ans
			continue

	for j in range(N):
		tmp_ans = ans
		if 0 < j:
			if B[j-1] == B[j]:
				ans += tmp
				tmp_ans += tmp
				continue

		if B[j] > A[i]:
			for k in range(N):
				if C[k] > B[j]:
					tmp = (N-k) 
					ans += (N-k) 
					break

		tmp_ans = ans - tmp_ans
			

print(ans)
