function [t, u] = Taylor_iter(func, inteval, u0, delta_t, order, F, G)
% TAYLOR_ITER The main function of Taylor series Iteration of solving ODEs
% The equation behave likes du/dt = f(t, u), with initial condition given 
% as u(0) = u0 in the inteval [a, b];

% input:
% func : a function of two variables t, u;
% inteval : a list of the inteval of the equation, given like [a, b];
% u0 : the initial condition;
% delta_t : the step size of time;
% order : the order of the iteration, chosen from {1, 2, 3};
% F : needed if the order = 2; 
% G: needed if the order = 3;

% output:
% t : the list of time, inited by the inteval and delta_t;
% u : the value of u at the points in t;

if nargin < 2
    error('More arguments needed --Taylor-iter');
elseif nargin == 2
    u0 = 1;
    delta_t = 1/8;
    order = 1;
elseif nargin == 3
    delta_t = 1/8;
    order = 1;
elseif nargin == 4
    order = 1;
end

if order == 2
    if nargin <= 5
        error('F is needed --Taylor-iter');
    end
elseif order == 3
    if nargin <= 6
        error('G is needed --Taylor-iter');
    end
end

if length(inteval) ~= 2 || inteval(1) >= inteval(2)
    error('Invalid inteval --Taylor-iter');
end

switch order
    case 1
        [t, u] = explicit_iter(func, inteval, u0, delta_t);
    case 2
        [t, u] = taylor_iter_2order(func, F, inteval, u0, delta_t);
    case 3
        [t, u] = taylor_iter_3order(func, F, G, inteval, u0, delta_t);
    otherwise
        error('Invalid order --Taylor-iter');
end

