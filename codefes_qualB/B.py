#! /usr/bin/env python3
# -*- coding: utf-8 -*-

A,B,C,D = map(int,input().split(" "))

ans = int(A)*1728 + int(B)*144 + int(C) * 12 +int(D)
print(ans)
