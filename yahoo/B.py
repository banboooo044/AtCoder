
a,b = map(int,input().split(" "))
c,d = map(int,input().split(" "))
e,f = map(int,input().split(" "))

dic = {1:0,2:0,3:0,4:0}
dic[a] += 1
dic[b] += 1
dic[c] += 1
dic[d] += 1
dic[e] += 1
dic[f] += 1

for key , val in dic.items():
    if val == 0 or val >= 3:
        print("NO")
        exit(0)

print("YES")