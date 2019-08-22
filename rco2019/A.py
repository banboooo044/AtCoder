import numpy as np
N = int(input())
x,y = np.empty(N),np.empty(N)
for i in range(N):
    x[i],y[i] = map(int,input().split(" "))
#x = np.random.randint(low=0,high=500,size=(200))
#y = np.random.randint(low=0,high=500,size=(200))
xy = np.append(x.reshape(1,200),y.reshape(1,200),axis=0)
c = np.cov(x,y)

w,v = np.linalg.eig(c)
z = (np.transpose(v)[0] @ xy)
zy = (np.transpose(v)[1] @ xy)

idx = np.argsort(z)
