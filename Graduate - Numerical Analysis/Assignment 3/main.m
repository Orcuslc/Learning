% Main Script
n = 1e7;
xx = n:-1:1;
a = single(1./xx);
b = single(1./(xx.^2));
c = single(1./(xx.^3));
d = single(((-1).^xx)./xx);

a1 = smallest_to_largest(a);
a2 = largest_to_smallest(a);
a0 = precise(a);
disp([abs(a0-a1) abs(a0-a2)]);

b1 = smallest_to_largest(b);
b2 = largest_to_smallest(b);
b0 = precise(b);
disp([abs(b0-b1) abs(b0-b2)]);

c1 = smallest_to_largest(c);
c2 = largest_to_smallest(c);
c0 = precise(c);
disp([abs(c0-c1) abs(c0-c2)]);

d1 = smallest_to_largest(d);
d2 = largest_to_smallest(d);
d0 = precise(d);
disp([abs(d0-d1) abs(d0-d2)]);