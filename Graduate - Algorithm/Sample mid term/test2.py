def att(S, n, t1, t2, t3):
	dp = [[[[False for i in range(t3+1)] for j in range(t2+1)] for k in range(t1+1)] for t in range(n+1)]
	dp[0][0][0][0] = True
	for t in range(1, n+1):
		for k in range(t1+1):
			for j in range(t2+1):
				for i in range(t3+1):
					dp[t][k][j][i] = (dp[t-1][k-S[t-1]][j][i] if k >= S[t-1] else False) or (dp[t-1][k][j-S[t-1]][i] if j >= S[t-1] else False)  or (dp[t-1][k][j][i-S[t-1]] if i >= S[t-1] else False)
	return dp[-1][-1][-1][-1]

S = [2,7,5,10]
print(att(S, 4, 9, 15, 0))