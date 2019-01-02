a,b = map(int,input().split(" "))
dif = b - a
print((dif * (dif + 1) // 2) - b)