#A問題
X,Y = map(str,input().split(" "))

if ord(X) < ord(Y):
	print("<")
elif ord(X) == ord(Y):
	print("=")
else:
	print(">")