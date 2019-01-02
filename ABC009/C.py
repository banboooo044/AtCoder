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
				if (candidate[0] >= s_made[j]) and 1 + un_used[j] + count <= K:
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

N , K = map(int,input().split(" "))
S = input()
s_sorted = sorted(S)

un_used = [1] * N
words = dfs(0,0,list(S),un_used)
ans = ''.join(words)

print(ans)
