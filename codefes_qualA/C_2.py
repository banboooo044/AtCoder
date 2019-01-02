def func() :
    n,m=map(int,input().split())
    a={}
    for i in range(n) :
        s = input()
        for c in list(s):
            if c in a:
                a[c]+=1
            else :
                a[c] = 1
    c1=sum(map(lambda x : x%2 , a.values()))
    print(c1)
    c2=sum(map(lambda x : x//4*4, a.values()))
    print(c2)
    if c1 != n*m%2 or c2 < (n//2*2)*(m//2*2) :
        print('No')
    else :
        print('Yes')
func()