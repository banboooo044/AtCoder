A, B = map(int, input().split(" "))
if (B - 1) % (A - 1) == 0:
    print((B - 1) // (A - 1))
else:
    print(((B - 1) // (A - 1)) + 1)
