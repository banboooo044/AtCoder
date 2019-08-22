A,B,C = map(int,input().split(" "))

cnt = 0
while True:
    if A % 2 == 1 or B % 2 == 1 or C % 2 == 1:
        print(cnt)
        exit(0)
    elif A == B == C:
        print("-1")
        exit(0)
    
    A , B, C = (B+C)//2,(A+C)//2,(A+B)//2
    cnt += 1

