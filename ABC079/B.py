N = int(input())
ryuka = [0] * (N+1)

ryuka[0] = 2
ryuka[1] = 1

for i in range(2,N+1):
	ryuka[i] = ryuka[i-1] + ryuka[i-2]

print(ryuka[N])