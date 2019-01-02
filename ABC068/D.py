K = int(input())
print(50)

div = K // 50
margin = K % 50

#K回
for i in range(margin):
	print(str(49+50*(div+1)-(K-1*(div+1))) + " ",end="") 

for i in range(margin,50):
	print(str(49+51*div-K) + " ",end="")

print()
	


