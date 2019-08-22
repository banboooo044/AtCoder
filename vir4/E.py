s = input()
num = [ int(i) for i in s]

for i in range(2):
    for j in range(2):
        for k in range(2):
            ans = str(num[0])
            val = num[0]
            if i == 0:
                ans += "+"
                val += num[1]
            else:
                ans += "-"
                val -= num[1]
            ans += str(num[1])
            if j == 0:
                ans += "+"
                val += num[2]
            else:
                ans += "-"
                val -= num[2]
            ans += str(num[2])
            if k == 0:
                ans += "+"
                val += num[3]
            else:
                ans += "-"
                val -= num[3]
            ans += str(num[3])
            if val == 7:
                print(ans + "=7")
                exit(0)
            

                
                

