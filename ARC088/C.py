X,Y = map(int,input().split(" "))

div = Y // X 

num = 1
count = 1
while div >= num:
	num <<= 1
	count += 1

print(count-1)