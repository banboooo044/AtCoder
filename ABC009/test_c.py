import random
import string

def dfs(i,count,s_made,un_used):
	#print("i ==> ",i)
	#print("count ==> ",count)
	#print(s_made)
	if i == N:
		return s_made

	if un_used[i] == 1:
		if s_made[i] == s_sorted[i] or count == K:
			return dfs(i+1,count,s_made,un_used)

		else:
			s_changed = s_made[:]
			un_used_changed = un_used[:]
			candidate = [s_made[i],i,0]
			increment = 0

			for j in range(N-1,i,-1):
				if s_made[j] == s_sorted[i] and un_used[j] == 0:
					increment = 1
					s_changed[i] = s_sorted[i]
					s_changed[j] = s_made[i]
					un_used_changed[i] = 0
					return dfs(i+1,count + increment,s_changed,un_used_changed)

				elif (candidate[0] >= s_made[j]) and 1 + un_used[j] + count <= K:
					if (candidate[0] == s_made[j]) and (candidate[2] <= un_used[j]):
						continue
					else:
						candidate = [s_made[j],j,un_used[j]]
			
				
			if candidate[0] != s_made[i]:
				s_changed[i] = candidate[0]
				s_changed[candidate[1]] = s_made[i]
				un_used_changed[i] = 0
				un_used_changed[candidate[1]] = 0
				return dfs(i+1,count + candidate[2] + 1,s_changed,un_used_changed)			

			else: 
				return dfs(i+1,count,s_made,un_used)

	else:
		s_changed = s_made[:]
		un_used_changed = un_used[:]
		candidate = [s_made[i],i,0]

		for j in range(N-1,i,-1):
			if (candidate[0] >= s_made[j]) and un_used[j] + count <= K:
				if (candidate[0] == s_made[j]) and (candidate[2] <= un_used[j]):
					continue
				else:
					candidate = [s_made[j],j,un_used[j]]

		if candidate[0] != s_made[i]:
			s_changed[i] = candidate[0]
			s_changed[candidate[1]] = s_made[i]
			un_used_changed[candidate[1]] = 0
			return dfs(i+1,count+candidate[2],s_changed,un_used_changed)

		else:
			return dfs(i+1,count,s_made,un_used)

def main1(N,K,S):	
	words = dfs(0,0,list(S),un_used)
	ans = ''.join(words)
	return ans

def enable(s,t,k,a):
        t1 = list(t)
        t1.append(a)
        for i in range(len(t1)):
            if s[i] != t1[i]: k -= 1
        s2 = s[len(t1):]
        t2 = list(s)
        for l in t1:
            t2.pop(t2.index(l))
        for i in s2:
            if i in t2:
                t2.pop(t2.index(i))
        k -= len(t2)
        return k >= 0

def main2(n,k,s):
    ss = sorted(s)
    t = []
    for i in range(n):
        for l in ss:
            if enable(s,t,k,l):
                t.append(l)
                ss.pop(ss.index(l))
                break
    ans = "".join(t)

    return ans


if __name__ == "__main__":
	#n = random.randint(1,20)
	#k = random.randint(1,20)
	#random_str = ''.join([random.choice(string.ascii_lowercase) for i in range(n)])

	
	n , k = map(int,input().split(" "))
	random_str = input()

	print(str(n) + " " + str(k))
	print(random_str)
	print("----------------------------------------------------")
	s_sorted = sorted(random_str)
	un_used = [1] * n
	N = n
	K = k
	S = random_str

	ans1 = main1(n,k,random_str) 
	ans2 = main2(n,k,random_str)
	if ans1 == ans2:
		print("ok")
	else:

		print("no")










