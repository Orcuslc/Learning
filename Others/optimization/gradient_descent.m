function x = gradient_descent(f, gradf, dom, x0, alpha, beta, tol, max_iter)
% Gradient Descent with backtracking;
% f, gradf: the target function and its gradients;
% dom: Dom of f, a function w/ return value T/F.
% x0: init val;
% alpha, beta: backtracking parameters;
% tol, max_iter: grad tolerance and max iteration;

x = x0;
for i = 1:max_iter
    grad = feval(gradf, x);
    if norm(grad, 2) < tol
        break;
    end
    dir = -grad;
    t = 1;
    while(~feval(dom, x+t*dir))
        t = beta*t;
    end
    while(feval(f, x+t*dir) > feval(f, x)+alpha*t*transpose(grad)*dir)
        t = beta*t;
    end
    x = x+t*dir;
end