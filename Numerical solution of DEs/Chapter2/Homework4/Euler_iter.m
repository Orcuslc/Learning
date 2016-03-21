function [ t, u ] = Euler_iter( func, inteval, u0, delta_t, op )
% EULER_ITER The main function of Euler Iteration of solving ODEs
% The equation behave likes du/dt = f(t, u), with initial condition given 
% as u(0) = u0 in the inteval [a, b];

% input:
% func : a function of two variables t, u;
% inteval : a list of the inteval of the equation, given like [a, b];
% u0 : the initial condition;
% delta_t : the step size of time;
% op : the kind of iterations, chosen from "explicit', 'implicit',
% 'modified', 'revised';

% output:
% t : the list of time, inited by the inteval and delta_t;
% u : the value of u at the points in t;

if nargin < 2
    error('More arguments needed --Euler-iter');
elseif nargin == 2
    u0 = 1;
    delta_t = 1/8;
    op = 'explicit';
elseif nargin == 3
    delta_t = 1/8;
    op = 'explicit';
elseif nargin == 4
    op = 'explicit';
end

if length(inteval) ~= 2 || inteval(1) >= inteval(2)
    error('Invalid inteval --Euler-iter');
end

switch op
    case 'explicit'
        [t, u] = explicit_iter(func, inteval, u0, delta_t);
    case 'implicit'
        [t, u] = implicit_iter(func, inteval, u0, delta_t);
    case 'modified'
        [t, u] = modified_iter(func, inteval, u0, delta_t);
    case 'revised'
        [t, u] = revised_iter(func, inteval, u0, delta_t);
    otherwise
        error('Invalid operation --Euler-iter');
end

end

