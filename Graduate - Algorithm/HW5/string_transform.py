import random
import string

def edit(a, b):
	return (0 if a == b else 1)

def transform(source, target):
	n = len(source)
	# flip[i][j]: the min operations (substitution only) to transform source[i:j+1] to target[i:j+1] after a flip on source[i:j+1]. Here we use Python indices.
	# dp[i]: the min operations to transform source[:i+1] to target[:i+1]. Use Python indices.
	flip = [[0 for i in range(n)] for i in range(n)]
	dp = [n for i in range(n)]
	dp[0] = edit(source[0], target[0])
	flip[0][0] = dp[0]
	for i in range(1, n):
		dp[i] = edit(source[i], target[i])+dp[i-1]
		flip[i][i] = edit(source[i], target[i])
		for j in range(i-1, -1, -1):
			flip[j][i] = edit(source[i], target[j])+edit(source[j], target[i])
			if j+1 <= i-1:
				flip[j][i] += (flip[j+1][i-1])
			dp[i] = min((0 if j == 0 else dp[j-1])+flip[j][i]+1, dp[i])
	return dp[n-1]



# src = "anarrow"
# dst = "worrbna"

# src = "timeflieslikeanarrow"
# dst = "tfemiliilzejeworrbna"

# src = "abcde"
# dst = "cdcbb"
N = 1000

src = "".join(random.choice(string.ascii_lowercase) for _ in range(N))
dst = "".join(random.choice(string.ascii_lowercase) for _ in range(N))

if __name__ == '__main__':
	print(transform(src, dst))