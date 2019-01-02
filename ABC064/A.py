N = int(input())
a =  list(map(int,input().split(" ")))

free = 0
arr = [0] * 8

for i in a:
	limit = 400
	while (limit <= 3200):
		if i < limit:
			arr[(limit // 400)-1] +=  1
			break
		else:
			limit += 400

	if limit== 3600:
		free += 1

color =  0
for i in arr:
	if i > 0:
		color += 1


print(str(max(1,color)) + " " + str(color + free))


