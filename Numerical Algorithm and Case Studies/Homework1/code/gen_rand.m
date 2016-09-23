function[A, b] = gen_rand(n)
% Generate a random matrix and a random vector;

A = rand(n);
b = rand([n, 1]);