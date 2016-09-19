kmeans = function(A, k, max_iter = 1000, min_error = 1e-4) {
  # Kmeans, using Lloyd Algorithm;
  # A: The data matrix, each record being a row;
  # k: The number of cluster centers;
  # max_iter: The number of max iteration;
  # min_error: The min error for stable judgement;
  
  ndata = nrow(A);  # The length of data;
  narg = ncol(A);  # The number of arguments;
  center_index = sort(sample(1:ndata, k));  # The init index of cluster centers;
  centers = A[center_index, ];  # The data of centers;
  ncenters = matrix(rep(0, k*narg), ncol = narg);
  type = c(rep(0, ndata));  # The type of each points;
  count = 0;  # Number of iter count;
  
  while(TRUE && count <= max_iter) {
    for(i in 1:ndata) {
      type[i] = nearest_center(A[i, ], centers);
    }
    for(i in 1:k) {
      ncenters[i, ] = colMeans(A[which(type == i), ]);
    }
    # if(identical(centers, ncenters)) {
    if(is_stable(centers, ncenters, min_error)) {
      break;
    }
    count = count + 1;
    centers = ncenters;
    print(count);
  }
  return(type);
}

is_stable = function(C1, C2, min_error) {
  return(norm(C1 - C2, type = "2") <= min_error);
}

calc_dist = function(x1, x2) {
  # Calculate the distance between two points;
  return(sum((x1-x2)^2));
}

nearest_center = function(x, C) {
  # Assign a point to a center;
  k = nrow(C);
  dist = c(rep(0, k));
  for(i in 1:k) {
    dist[i] = calc_dist(x, C[i, ]);
  }
  return(which(dist == min(dist))[1]);
}