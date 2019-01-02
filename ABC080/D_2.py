L = 100005
n,c = map(int,input().split(" "))

# arr[col] には、区間の始まり ==> 1,区間中 ==> 0,区間終わり ==> -1
# 連続した区間は結合した形で表現される

arr = [[0]*L for _ in range(c)]

for i in range(n):
    s,t,col = map(int,input().split(" "))
    arr[col-1][s-1] += 1
    arr[col-1][t-1] -= 1

imos = [0]*L

#全チャンネルを同時に考えたいもす法
for i in range(c):
    for p in range(L):
        if arr[i][p] == 1: imos[p] += 1    
        if arr[i][p] == -1: imos[p+1] -= 1


#累積和をとれば、区間内の最大のrec数は値のmax.
ans = 0
for i in range(1,L):
    imos[i] += imos[i-1]
    ans = max(ans, imos[i])

print(ans)
