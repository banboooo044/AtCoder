# B問題
S = input()
var_str = {'a':0,'b':0,'c':0}
var_list = []

for i in S:
	var_str[i] += 1

for i,j in var_str.items():
	var_list.append((i,j))

var_list.sort(key = lambda x:x[1])

first = var_list[-1][1]
second = var_list[1][1]
third = var_list[0][1]

first -= third 
second -= third

if first <= 1 and second <= 1:
	print("YES")
else:
	print("NO")
