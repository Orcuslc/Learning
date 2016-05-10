function [t, u] = Adams_iter(func, inteval, ulist, delta_t, op, order)
% Adams_ITER The main function of Adams Iteration of solving ODEs
% The equation behave likes du/dt = f(t, u), with initial condition given 
% as u(0) = u0 in the inteval [a, b];

% input:
% func : a function of two variables t, u;
% inteval : a list of the inteval of the equation, given like [a, b];
% ulist : the initial condition;
% delta_t : the step size of time;
% op : the kind of iterations, chosen from 'B', 'M';
% order : the order of iteration, chosen from 0,1,2,3,4;

% output:
% t : the list of time, inited by the inteval and delta_t;
% u : the value of u at the points in t;

if nargin < 2
    error('More arguments needed --Adams-iter');
elseif nargin == 2
    ulist = 0;
    delta_t = 1/8;
    op = 'B';
    order = 0;
elseif nargin == 3
    delta_t = 1/8;
    op = 'B';
    order = 0;
elseif nargin == 4
    op = 'B';
    order = 0;
elseif nargin == 5
    order = 0;
end

if length(inteval) ~= 2 || inteval(1) >= inteval(2)
    error('Invalid inteval --Euler-iter');
end

if op == 'B'
    switch order
        case 0
            [t, u] = explicit_iter(func, inteval, ulist, delta_t);
        case 1
            [t, u] = AB1_iter(func, inteval, ulist, delta_t);
        case 2
            [t, u] = AB2_iter(func, inteval, ulist, delta_t);
        case 3
            [t, u] = AB3_iter(func, inteval, ulist, delta_t);
        otherwise
            error('Invalid operation --Adams-iter');
    end
elseif op == 'M'
    switch order
        case 0
            [t, u] = implicit_iter(func, inteval, ulist, delta_t);
        case 1
            [t, u] = AM1_iter(func, inteval, ulist, delta_t);
        case 2
            [t, u] = AM2_iter(func, inteval, ulist, delta_t);
        case 3
            [t, u] = AM3_iter(func, inteval, ulist, delta_t);
        otherwise
            error('Invalid operation --Adams-iter');
    end
end




            