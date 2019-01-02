a = [[[[4],[6]],[[7],[0]]],[[[1],[2]],[[0],[1]]],[[[8],[1]],[[9],[2]]]]
def min_max(turn,alpha,beta,arr):
	al,be = alpha,beta
	if len(arr) == 1:
		return arr[0]
	else:
		ret = float('inf') if turn % 2 else -float('inf')
		for lis in arr:
			val = min_max(turn+1,al,be,lis)
			if turn % 2:
				if al >= val:
					print(lis)
					print(val)
					print()
					ret = -float('inf')
					break
				else:
					ret = min(val,ret)
					be = min(ret,be)
			else:
				if be <= val:
					print(lis)
					print(val)
					print()
					ret = float('inf')
					break
				else:
					ret = max(val,ret)
					al = max(ret,al)

			print(lis)
			print("alpha beta")
			print(al,be)
			print()

		return ret

print(min_max(0,-float('inf'),float('inf'),a))
				
