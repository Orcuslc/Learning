function [u] = accurate(a, b, c, t)
    delta = sqrt(b^2+4*a*c);
    l1 = (b+delta)/(2*a); l2 = (b-delta)/(2*a);
    e1 = exp(l1); e2 = exp(l2);
    u = (e2-1-l1)/(c*((1+l2)*e1-(1+l1)*e2))*exp(l1*t) + (e1-1-l2)/(c*((1+l1)*e2-(1+e2)*e1))*exp(l2*t)+1/c;