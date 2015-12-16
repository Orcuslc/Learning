def fast_transpose_matrix(M):
	T = Matrix()
	T.mu = M.nu
	T.nu = M.mu
	T.tu = M.tu
	num = []
	if T.tu > 0:
		for col in range(M.nu):
			num.append(0)
		for t in range(M.tu):
			num[M.data[t].j] += 1
		cpot[0] = 1
		for col in range(1, M.nu):
			cpot.append(copt[-1] + num[col - 1])
		for p in range(M.tu):
			col = M.data[p].j
			q = cpot[col]
			T.data[q].j = M.data[p].i
			T.data[q].e = M.data[p].e
			cpot[col] += 1
	return T