A,B,C = map(int,input().split(" "))
K = int(input())
print(max([A,B,C])*((1 << (K))-1) + sum([A,B,C]))