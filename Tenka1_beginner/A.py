#! /usr/bin/env python3
# -*- coding: utf-8 -*-

S = input()

numList = list(S)

count = 0
for i in numList:
	if i == "1":
		count += 1

print(count)n