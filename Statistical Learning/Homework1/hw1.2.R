a# Homework 1.2
source("kmeans.R");
source("evaluate.R")

##################################################################
#################      For Data1.csv     #########################
##################################################################
data = read("Data1.csv");
k = 3;
type = kmeans(data, k, max_iter = 10000, min_error = 1e-8)[[1]];
plot_points(data, type, k);
max_k = 20;
CH = evaluate_CH(data, max_k);
plot(1:max_k, CH, type = 'o');
H = evaluate_H(data, max_k = max_k);
plot(1:max_k, H, type = 'o');
res = evaluate_GAP(data, max_k = max_k);
print(res);
plot(1:max_k, res[[2]], type = 'o');

#################################################################
##################      For Data2.csv    ########################
#################################################################
data = read("Data2.csv");
k = 3;
type = kmeans(data, k, max_iter = 10000, min_error = 1e-8)[[1]];
print(type)
# plot_points(data, type, k);
max_k = 20;
CH = evaluate_CH(data, max_k);
plot(1:max_k, CH, type = 'o');
H = evaluate_H(data, max_k = max_k);
plot(1:max_k, H, type = 'o');
res = evaluate_GAP(data, max_k = max_k);
print(res);
plot(1:max_k, res[[2]], type = 'o');


#################################################################
##################      For Data3.csv    ########################
#################################################################
data = read("Data3.csv");
k = 3;
type = kmeans(data, k, max_iter = 10000, min_error = 1e-8)[[1]];
print(type)
# plot_points(data, type, k);
max_k = 20;
CH = evaluate_CH(data, max_k);
plot(1:max_k, CH, type = 'o');
H = evaluate_H(data, max_k = max_k);
plot(1:max_k, H, type = 'o');
res = evaluate_GAP(data, max_k = max_k);
print(res);
plot(1:max_k, res[[2]], type = 'o');


#################################################################
##################      For Data4.csv    ########################
#################################################################
data = read("Data4.csv");
k = 3;
type = kmeans(data, k, max_iter = 10000, min_error = 1e-8)[[1]];
print(type)
# plot_points(data, type, k);
max_k = 20;
CH = evaluate_CH(data, max_k);
plot(1:max_k, CH, type = 'o');
H = evaluate_H(data, max_k = max_k);
plot(1:max_k, H, type = 'o');
res = evaluate_GAP(data, max_k = max_k);
print(res);
plot(1:max_k, res[[2]], type = 'o');

