Q = int(input())
A,B = 0,0
a_list = []
e = 0
for i in range(Q):
    query = list(map(int,input().split(" ")))
    if query[0] == 1:
        a,b = query[1],query[2]
        a_list.append(a)
        A += a
        B += b
        e += 1
    else:
        x = A // e
        print("{0} {1}".format(x, B + sum(list(map(lambda v: abs(v - x) ,a_list)))))
