function val = Hermite_poly(xx, fx, x)
% Hermite Polynomial;

n = length(xx);
H = zeros(n, n);

% get coefficients
for i=1:n
    H(i, 1) = fx(find(xx == xx(i), 1, 'first'));
end;

for i=2:n
    for j=1:(n-i+1)
        pos1 = find(xx == xx(j), 1, 'first');
        pos2 = find(xx == xx(i+j-1), 1, 'first');
        if pos1 == pos2
            H(j, i) = fx(pos1+i-1)/factorial(i-1);
        else
            H(j , i) = (H(j+1, i-1)-H(j, i-1))/(xx(i+j-1)-xx(j));
        end
    end
end
val = H(1, n);
for i=(n-1):-1:1
    val = val.*(x-xx(i))+H(1, i);
end