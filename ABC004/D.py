R,G,B = map(int,input().split(" "))
if B < R:
	R,B = B,R
b_max = (G//2+B+1)
b_min = (B//2)

v = float('inf')
for b in range(b_min,b_max+1):
	ans = 0
	if b >= B:
		ans += (((b+1)*b//2) - ((b - B + 1)*(b - B)//2))
	else:
		ans += (((b+1)*b//2) + ((B-b)*(B-b-1)//2))
	
	b_f = abs(min(b - B + 1,0)) # b_fはG側にはみ出している数

	if (G // 2) + b_f <= 99:
		if G % 2 == 1:
			ans += ((G//2)*((G//2)+1))
		else:
			ans += ((G//2)*((G//2)-1)//2) + ((G//2)*((G//2)+1)//2)

		if R % 2 == 1:
			ans += (R//2)*((R//2)+1)
		else:
			ans += (((R//2)*((R//2)+1) + (R//2)*((R//2)-1))//2)

	elif b_f <= 99:
		b_f = 99 - b_f
		ans += (b_f*(b_f+1)//2)
		ans += ((G-b_f)*(G-b_f-1)//2)
		r_f = 100 - (G - b_f)
		r_m = R//2 if R % 2 == 1 else (R//2 - 1)
		if r_f >= r_m:
			ans += ((r_m*(r_m+1)//2) + ((R//2)*(R//2+1)//2))
		elif r_f >= 0:
			ans += (r_f*(r_f+1)//2) + ((R - r_f - 1)*(R-r_f)//2)
		else:
			ans += (((abs(r_f)+R)*(abs(r_f)+R+1)//2) - ((abs(r_f))*(abs(r_f)+1)//2))

	else:
		b_f -= 100
		ans += ((G+b_f+1)*(G+b_f)//2) - ((b_f)*(b_f+1)//2)
		r_f = 99 - (G + b_f)
		r_m = R//2 if R % 2 == 1 else (R//2 - 1)
		if r_f >= r_m:
			ans += ((r_m*(r_m+1)//2) + ((R//2)*(R//2+1)//2))
		elif r_f >= 0:
			ans += (r_f*(r_f+1)//2) + ((R - r_f - 1)*(R-r_f)//2)
		else:
			ans += (((abs(r_f)+R)*(abs(r_f)+R+1)//2) - ((abs(r_f))*(abs(r_f)+1)//2))

	v = min(ans,v)

print(v)



