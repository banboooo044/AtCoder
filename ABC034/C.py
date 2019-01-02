from scipy.misc import comb
W,H = map(int,input().split(" "))
print(comb(W+H-2,W-1)%1000000007)
