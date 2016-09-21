# Homework 1.3
source("hierarchical_clustering.R")
source("kmeans.R")

###########################################
##########  For Data1.csv  ################
##########################################
data = read("Data1.csv");
single = hc(data, linkage = 'single');
complete = hc(data, linkage = 'complete');
average = hc(data, linkage = 'average');
single
complete
average

###########################################
##########  For Data2.csv  ################
##########################################
data = read("Data2.csv");
single = hc(data, linkage = 'single');
complete = hc(data, linkage = 'complete');
average = hc(data, linkage = 'average');
single
complete
average

