# D

H, W = map(int, input().split())

P_list = []
F_list = []

for _ in range(H):
    P_list.append(list(map(int, input().split())))

for _ in range(H):
    F_list.append(list(map(int, input().split())))
    

DP = [-10000000000]*W
DP[0] = 0
DP_ = DP.copy()

left_move = [0]*W
right_move = [0]*W

for j in range(H):

    for i in range(W):
        if i == 0:
            pass
        else:
            left_move[i] = max(left_move[i-1] + P_list[j][i-1] - F_list[j][i-1] - F_list[j][i], 0)
            right_move[W-1-i] = max(right_move[W-i] + P_list[j][W-i] - F_list[j][W-i] - F_list[j][W-1-i], 0)

    # left to right
    D_1 = -10000000000
    for i in range(W):
        D_1 = max(DP[i] + left_move[i], D_1) + P_list[j][i] - F_list[j][i]
        DP_[i] = D_1 + right_move[i]
    # right to left
    D_1 = -10000000000
    for i in range(W-1, -1, -1):
        D_1 = max(DP[i] + right_move[i], D_1) + P_list[j][i] - F_list[j][i]
        DP_[i] = max(DP_[i], D_1 + left_move[i])
        
    DP = DP_.copy()
    
for p in DP:
    print(p)