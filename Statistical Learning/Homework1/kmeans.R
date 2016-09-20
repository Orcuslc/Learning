kmeans = function(A, k, max_iter = 1000, min_error = 1e-6) {
  # Kmeans, using Lloyd Algorithm;
  # While one of the types have NO points,
  # Kick the farthest point in the largest type out and mark it the NULL type;
  
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
    
  # To add robustance; rearrange types;
    while(TRUE) {
      type_count = rep(0, k);
      for(j in 1:k) {
        type_count[j] = length(which(type == j));
      }
      if(min(type_count) > 0) {
        break;
      }
      largest_type = which(type_count == max(type_count))[1];
      for(j in 1:k) {
        if(type_count[j] == 0) {
          # type[which(type == largest_type)[1]] = j;
          t = which(type == largest_type);
          B = A[t, ];
          ln = length(t);
          dist_t = rep(0, ln);
          for(m in 1:ln) {
            print(t[m])
            dist_t = calc_dist(B[m, ], centers[largest_type, ]);
          }
          min_t = which(dist_t == min(dist_t))[1];
          type[which(type == largest_type)[min_t]] = j;
        }
      }
    }
  
  	for(i in 1:k) {
  	  A_t = A[which(type == i), ];
  	  ncenters[i, ] = update_centers(A_t);
  	}
  	if(is_stable(centers, ncenters, min_error)) {
  	  break;
  	}
  	count = count + 1;
  	centers = ncenters;
    }
    res = list(type, centers)
    return(res);
}

update_centers = function(A_t) {
  ## Update centers;
  ## We use the improvement here: Use one REAL DATA POINT (closest to all)
  ## (Instead, closest to the AVERAGE)
  ## instead of average as the center of the cluster;
  ## Calculate the sum of distances to judge which point should be the center;
  if(is.null(nrow(A_t))) {
	  return(A_t);
  }
#   else {
#     avg = colMeans(A_t);
#     dists = rep(0, nrow(A_t));
# 	  for(i in 1:nrow(A_t)) {
# 		  # sum = 0;
# 	  	# for(j in 1:nrow(A_t)) {
# 	  	# 	sum = sum + calc_dist(A_t[i, ], A_t[j, ]);
# 	  	# }
# 	  	# dists[i] = sum;
# 	    dists[i] = calc_dist(A_t[i, ], avg);
# 	  }
#   print(A_t[which(dists == min(dists)), ]);
# 	return(A_t[which(dists == min(dists))[1], ])
#   }
  else {
    return(colMeans(A_t));
  }
} 

is_stable = function(C1, C2, min_error) {
  # Judge if the centers is stable;
  return(sum((C1-C2)^2) <= min_error);
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

plot_points = function(A, type, k) {
  # Plot points and type;
  x1 = min(A[, 1])*1.1;
  x2 = max(A[, 1])*1.1;
  y1 = min(A[, 2])*1.1;
  y2 = max(A[, 2])*1.1;
  plot(c(x1, x1, x2, x2), c(y1, y2, y1, y2));
  cl = colors();
  bcol = floor(657/k);
  for(i in 1:nrow(A)) {
    colc = bcol * type[i];
    points(A[i, 1], A[i, 2], type = 'o', col = cl[colc], pch = 19);
  }
  for(i in 1:k) {
    x = A[which(type == i), 1];
    y = A[which(type == i), 2];
    hull = chull(x, y);
    polygon(x[hull], y[hull]);
  }
}

read = function(path) {
  # Used to read CSVs;
  data = read.csv(path);
  data = as.matrix(data)[, 2:ncol(data)];
  colnames(data) = NULL;
  return(data);
}

