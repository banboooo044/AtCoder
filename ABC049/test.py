with open('./true.txt','r') as obj:
	data = obj.read()
with open('./out.txt','r') as obj:
	data2 = obj.read()

with open('./test2.txt','r') as obj:
	data3 = obj.read()

data = list(map(int,data.split(" ")))
data2 = list(map(int,data2.split(" ")))


for i,j,k in zip(data,data2,range(len(data))):
	if abs(i - j) > 30000:
		print(i,j,k)