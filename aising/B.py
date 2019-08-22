N = int(input())
A,B = map(int,input().split(" "))
P = list(map(int,input().split(" ")))

one,two,three = 0,0,0
for i in range(N):
    if P[i] <= A:
        one += 1
    elif P[i] > A and P[i] <= B:
        two += 1
    else:
        three += 1


print(min([one,two,three]))