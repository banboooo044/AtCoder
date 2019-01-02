# 例えば ダブり分が　10 2 2 なら
# 8 2 2 -> 6 2 2 -> 4 2 2 と、3以上あるものを先に減らしてあげれば必ず他を一個も使わず終わらせられる。

N = int(input())
A = list(map(int,input().split(" ")))
print(len(set(A)) - ((len(set(A))+1) % 2))