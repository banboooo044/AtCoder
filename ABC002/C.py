#! usr/bin/env python3
# -*- coding:utf-8 -*-

# C:直訴

X_a,Y_a,X_b,Y_b,X_c,Y_c = map(int,input().split(" "))

X_b -= X_a
X_c -= X_a

Y_b -= Y_a
Y_c -= Y_a

S = abs(X_b*Y_c - X_c*Y_b)/2

print(S)