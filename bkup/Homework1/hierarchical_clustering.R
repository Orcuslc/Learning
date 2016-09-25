source('kmeans.R')

hc = function(A, linkage = 'single') {
  # Hierarchical Clustering: The request is that no two data points are the same.
  # A: The data matrix;
  # linkage: The mode of linkage, choose from ['single', 'complete', 'average'];
  ndata = nrow(A);
  for(i in 1:(ndata - 1)) {
    for(j in (i+1):ndata) {
      if(identical(A[i, ], A[j, ])) {
        cat("ERROR: There are two data points of the same");
        return(0);
      }
    }
  }
  TEMP = A;
  status = rep(0, ndata); # The flag to mark if a node has been merged; 0:no; 1:yes;
  dist_matrix = matrix(rep(0, ndata*ndata), ncol = ndata);
  pairs = matrix(rep(0, 2*(ndata-1)), ncol = 2);
  for(i in 1:ndata) { # Init The dist_matrix
    for(j in 1:ndata) {
      if(i != j) {
        dist_matrix[i, j] = calc_dist(A[i, ], A[j, ]);
      }
    }
  }
  for(i in 1:(ndata - 1)) {
    res = update_node(A, dist_matrix, status, linkage);
    pair = res[[1]];
    pairs[i, ] = pair;
    dist_matrix = res[[2]];
  }
  return(pairs);
}

update_node = function(A, dist_matrix, status, linkage) {
  # Find a nearest node and update the nodes;
  # A: The data matrix;
  # status: The status vector to flag if a node has been merged;
  #         if so, it should be considered Inf;
  ndata = nrow(A);
  narg = ncol(A);
  # print(dist_matrix);
  # print(min(dist_matrix[which(dist_matrix != 0)]))
  min_pair = which(dist_matrix == min(dist_matrix[which(dist_matrix != 0)]))[1];
  # print(min_pair)
  x2 = min_pair %% ndata;
  if(x2 == 0) {
    x2 = ndata;
  }
  x1 = (min_pair - x2) / ndata + 1;
  # print(c(x1, x2, dist_matrix[x1, x2]))
  if(linkage == 'single') {
    for(j in 1:ndata) {
      if(j != x1){
        dist_matrix[x1, j] = min(dist_matrix[x1, j], dist_matrix[x2, j]);
        dist_matrix[j, x1] = min(dist_matrix[j, x1], dist_matrix[j, x2]);
      }
      dist_matrix[j, x2] = 0.0;
    }
  }
  else if(linkage == 'complete') {
    for(j in 1:ndata) {
      if(j != x1) {
        dist_matrix[x1, j] = max(dist_matrix[x1, j], dist_matrix[x2, j]);
        dist_matrix[j, x1] = max(dist_matrix[j, x1], dist_matrix[j, x2]);
      }
      dist_matrix[j, x2] = 0.0;
    }
  }
  else if(linkage == 'average') {
    u = norm(A[x1, ], type = "2");
    v = norm(A[x2, ], type = "2");
    for(j in 1:ndata) {
      if(j != x1) {
        dist_matrix[x1, j] = (u*dist_matrix[x1, j]+v*dist_matrix[x2, j])/(u+v);
        dist_matrix[j, x1] = (u*dist_matrix[j, x1]+v*dist_matrix[j, x2])/(u+v);
      }
      dist_matrix[j, x2] = 0.0;
    }
  }
  dist_matrix[x2, ] = 0.0;
  return(list(c(x1, x2), dist_matrix));
}

draw_tree = function(A, pairs) {
  
}