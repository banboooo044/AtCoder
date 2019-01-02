#C問題 together
 
N = int(input())
a = list(map(int,input().split(" ")))
 

 
minval = min(a)
maxval = max(a)
l = (maxval - minval +1)
 
num = [0]*(l+2)

for i in a:
	num[i-minval] += 1

ans = 0
for i in range(1,l+1):
	ans = max(ans,num[i-1]+num[i]+num[i+1])

print(ans)






