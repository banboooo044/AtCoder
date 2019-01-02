A,B = map(int,input().split(" "))

if A == 1 and B == 1:
	print("1 2")
	print("#.")
	exit(0)

w = (max(A,B)-1) * 2
black = '#' * w
white = '.' * w
if A >= B:
	s1 = black + '\n'
	s2 = '.#' * (w//2) + '\n'
	s3 = black + '\n'
	s4 = white + '\n'
	s5 = ('#.' * (B-1)) + ('.') * (w-2*(B-1)) + '\n'
	s6 = white + '\n'

else:
	s1 = white + '\n'
	s2 = '#.' * (w//2) + '\n'
	s3 = white + '\n'
	s4 = black + '\n'
	s5 = ('.#' * (A-1)) + ('#') * (w-2*(A-1)) + '\n'
	s6 = black + '\n'

print("6 " + str(w))
print(s1 + s2 + s3 + s4 + s5 + s6)

