R, G ,B, N = map(int,input().split(" "))

cnt = 0
for i in range(0,N//R+1):
    for j in range(0,N//G+1):
        if R*i + G*j > N:
            break
        
        if (N - R*i - G*j) % B == 0:
            cnt += 1
            
print(cnt)