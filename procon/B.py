X,K = map(int,input().split(" "))

incre = (10 ** K)
print(X - (X % incre) + incre)


