data = read.csv('assign2.csv')
row = nrow(data)
col = ncol(data)
tdata = data[, 2:col]
data = matrix(rep(0, row*(col-1)), nrow = row)
for (i in 1:col-1) {
  d = factor(tdata[, i], levels = c('L', 'R'), labels = c('1', '2'))
  d = as.numeric(d)
  data[, i] = matrix(d)
}

# data = matrix(c(2,2,2,2,2), ncol=1)
source("hmm.R")
hidden_states = 2
observed_states = 2
rlist = baum_welch(data, hidden_states, observed_states)
a = rlist[[1]]
e = rlist[[2]]
s1 = viterbi(matrix(data[, 1]), a, e)
s2 = viterbi(matrix(data[, 2]), a, e)