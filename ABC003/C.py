#! usr/bin/env python3
 
#C:atcoderプログラミング講座
 
 
N,K = map(int,input().split(" "))



#intリストを作るときはこのように初めからint型でリストを作っておいた方良い。
R = list(map(int,input().split(" ")))
 
R.sort()
 
val =  0
 
for time in range(N-K,N):
	val += R[time]
	val /= 2
 
print(val)