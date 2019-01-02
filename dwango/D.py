N = int(input())
x = list(map(int,input().split(" ")))
if N == 1:
	print(x[0])
	exit(0)

a = list(map(int,input().split(" ")))
task = {}

need_task = [1]
que = [1]
while que != []:
	t = que.pop()
	for i in range(N-1):
		if a[i] == t:
			need_task.append(i+2)
			que.append(i+2)

for i in range(N-1):
	if not (a[i] in need_task):
		continue 

	if a[i] in task:
		task[a[i]] += x[i+1]

	else:
		task[a[i]] = x[i+1] + x[a[i]-1]

if task == {}:
	print(x[0])
else:
	print(max(task.values()))


