baum_welch = function(data, hidden_states, observed_states, max_iter=1000, max_error=1e-8) {
 
   # init parameters with hidden_states and observed_states;
  transition_matrix = matrix(rep(1, hidden_states^2), ncol = hidden_states)
  # transition_matrix = matrix(runif(hidden_states*hidden_states), nrow = hidden_states)
  transition_matrix = transition_matrix/rowSums(transition_matrix)
  emission_matrix = matrix(runif(hidden_states*observed_states), ncol = observed_states)
  emission_matrix = emission_matrix/rowSums(emission_matrix)
  
  # instrumental variables, A for transition_matrix, E for emission_matrix
  A = matrix(rep(0, hidden_states*hidden_states), nrow = hidden_states)
  E = matrix(rep(0, hidden_states*observed_states), ncol = observed_states)
  
  # Number of sequences and length of sequences;
  n_seq = ncol(data)
  len_seq = nrow(data)
  
  # Iteration
  for (step in 1:max_iter) {
    
    #print("step")
    print(step)
    # the lists saving the results of forward and backward algorithm, the x_th element 
    # is the result of the x_th sequence
    F_list = list()
    B_list = list()
    for (i in 1:n_seq) {
      F_list[[i]] = forward(matrix(data[, i], ncol=1), transition_matrix, emission_matrix)
      B_list[[i]] = backward(matrix(data[, i], ncol=1), transition_matrix, emission_matrix)
    }
    
    # We assume the probabilities for each sequence observed are the same;
    # And each time a multiplication is applied, a const related to the length of the
    # sequence should be multipled to it, so as to enlarge the result.
    # Step 1
    for (k in 1:hidden_states) {
      for (l in 1:hidden_states) {
        temp = 0
        for (j in 1:n_seq) {
          x = data[, j]
          F = F_list[[j]]
          B = B_list[[j]]
          for (i in 1:len_seq) {
            # Attemtion : We replace the i-1 in F[k ,i] for i
            #print(F[k, i]*transition_matrix[k, l]*emission_matrix[l, x[i]]*B[l, i])
            temp = temp + F[k, i]*transition_matrix[k, l]*emission_matrix[l, x[i]]*B[l, i]
          }
          temp = temp * (len_seq^5)
        }
        A[k, l] = temp
      }
    }
    
    # Step 2
    for (k in 1:hidden_states) {
      for (b in 1:observed_states) {
        temp = 0
        for (j in 1:n_seq) {
          x = data[, j]
          F = F_list[[j]]
          B = B_list[[j]]
          for (i in 1:len_seq) {
            if (x[i] == b) {
              temp = temp + F[k, i]*B[k, i]
            }
          }
          temp = temp * (len_seq^5)
        }
        E[k, b] = temp
      }
    }
    
    # Judging of convergence
    #print(A)
    Normalized_A = A/rowSums(A)
    Normalized_E = E/rowSums(E)
    error_A = sum(abs(transition_matrix - Normalized_A))
    error_E = sum(abs(emission_matrix - Normalized_E))
    #print(error_A, error_E)
    if (error_A < max_error & error_E < max_error) {
      break
    }
    
    # Step 3
    transition_matrix = Normalized_A
    emission_matrix = Normalized_E
    #print(emission_matrix)
  }
  
  # Return: A list of transition matrix and emission matrix
  returnlist = list(transition_matrix, emission_matrix)
  return(returnlist)
}

forward = function(x, a, e) {
  # forward algorithm;
  # a is the transition matrix and e is the emission matrix;
  # x is the observed sequence.
  n = nrow(x)
  
  # hs is the number of hidden states.
  hs = nrow(a)

  # F is the forward matrix;
  # The l_th row and i_th col means f_l(i);
  # The iteration of F is: f_l(i) = e[l, i]*\sigma_k(F[k, i-1] * a[k, l])
  F = matrix(rep(0, n*hs), ncol = n)
  F[, 1] = e[, 1]
  
  for (i in 2:n) {
    for (l in 1:hs) {
      F[l, i] = e[l, x[i]]*sum(F[, i-1]*a[, l])
    }
  }
  return(F)
}

backward = function(x, a, e) {
  # backward algorithm;
  # x is the observed sequence;
  # a is the transition matrix and e is the emission matrix;
  n = nrow(x)
  hs = nrow(a)
  
  # B is the backward matrix;
  # the i_th row and j_th col means b_i(j);
  # The iteration of B is: b_i(j) = \sigma_{s_k}P(s_k|s_i)P(x_{j+1}|s_k)b_k(j+1)
  B = matrix(rep(0, n*hs), ncol = n)
  B[, n] = matrix(rep(1, hs), ncol = 1)
  
  for (j in n-1:-1:1) {
    for (i in 1:hs) {
      B[i, j] = a[i, ] %*% (e[, x[j+1]] * B[, j+1])
    }
  }
  return(B)
}

viterbi = function(x, a, e) {
  # viterbi algorithm
  # x is the observed sequence, a is the state transition matrix,
  # and e is the emission matrix;
  n = nrow(x)
  hs = nrow(a)

  # v is the viterbi matrix;
  # the i_th row and j_th col is v_k(i)
  # The iteration of V is v_k(i) = P(x_i|s_i = k)*max_{l}{P(s_i=k|s_{i-1} = l)}v_l(i-1)
  # Attention : the first column of V is v_k(0)
  v = matrix(rep(0, (n+1)*hs), ncol = n + 1)
  v[1, 1] = 1

  for (i in 2:(n+1)) {
    for (l in 1:hs) {
      v[l, i] = e[l, x[i-1]] * max(v[, i-1] * a[, l])
    }
  }
  
  # S is the most probable sequence
  s = matrix(rep(0, n), nrow = 1)
  s[n] = which(v[, n+1] == max(v[, n+1]))

  for (i in (n-1):1) {
    temp = a[, s[i+1]] * v[, i+1]
    s[i] = which(temp == max(temp))
  }
  return(s)
}
