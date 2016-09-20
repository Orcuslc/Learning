# Homework 1.2
source("kmeans.R");


data = read("Data1.csv");
# print(data);
# type = kmeans(data, k = 3, max_iter = 10000, min_error = 1e-8)[[1]];
# plot(c(-10, -10, 10, 10), c(-10, 10, -10, 10));
# for(i in 1:length(type)) {
#   if(type[i] == 1) {
#     points(data[i, 1], data[i, 2], col = 'red');
#   }
#   else if(type[i] == 2) {
#     points(data[i, 1], data[i, 2], col = 'green');
#   }
#   else if(type[i] == 3) {
#     points(data[i, 1], data[i, 2], col = 'blue');
#   }
# }

# max_k = 10;
# CH = evaluate_CH(data, max_k);
# plot(1:max_k, CH)
k = 6;
type = kmeans(data, k = k, max_iter = 10000, min_error = 1e-8)[[1]];
# plot(c(-10, -10, 10, 10), c(-10, 10, -10, 10));
plot_points(data, type, k)
