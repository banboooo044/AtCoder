N,a = map(int,input().split(" "))
k = int(input())
b = list(map(int,input().split(" ")))

dic = {}
order = []
node = a
while True:
	if node in dic:
		i = order.index(node)		
		hd = order[:i]
		tl = order[i:]
		break
	else:
		dic[node] = 1
		order.append(node)
		node = b[node-1]

l = len(hd)
if l > k:
	print(hd[k])
else:
	print(tl[(k-l)%len(tl)])