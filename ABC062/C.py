H,W = map(int,input().split(" "))

if (H * W) % 3 == 0:
	print(0)
	exit(0)

st = (H*W//3)
candi_h = []
candi_w = []
candi_h.append(st - (st % H))
candi_h.append(st-(st % H) + H)
candi_h.append(st-(st % H) - H)
candi_w.append(st - (st % W))
candi_w.append(st - (st % W) + W)
candi_w.append(st - (st % W) - W)

ans = float('inf')
for sp in candi_h:
	if sp <= 0:
		continue
	other = (W - (sp // H)) * (H // 2)
	div = [sp,other,H*W-sp-other]
	ans = min(ans,max(div)-min(div))

for sp in candi_w:
	if sp <= 0:
		continue
	other = (H - (sp // W)) * (W // 2)
	div = [sp,other,H*W-sp-other]
	ans = min(ans,max(div)-min(div))

print(ans)