function [r1, r2] = extract_quadratic(b, c)
% The function to extract root of a quadratic equation
% x^2+bx+c = 0;

if nargin < 2
    error('More args needed');
end

delta = b^2-4*c;
if delta < 0
    error('Delta < 0, No real roots');
    return;
end

if c == 0
    r2 = 0; r1 = 0;
    return;
end
        
if b >= 0    
    t = b+sqrt(delta);
    r1 = -t/2;
    r2 = -2*c/t;
else
    t = -b+sqrt(delta);
    r1 = t/2;
    r2 = 2*c/t;
end