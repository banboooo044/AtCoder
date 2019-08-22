s = input()
target = "keyence"
l = len(target)
ls = len(s)
for i in range(len(target)):
    if s[:i] == target[:i] and s[ls-l+i:] == target[i:]:
        print("YES")
        exit(0)

print("NO")