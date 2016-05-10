lambdalist = [1, 10, 100, 1000];
u0list = [0, 1];
inteval = [0, 6];
delta_t = 0.1;
oplist = {'explicit', 'implicit'};
symbollist = {'*-', '.-'};
for i = 1:4
    figure(i);
    lambda = lambdalist(i);
    func = @(t, u)(lambda .* (-u + cos(t)));
    for j = 1:2
        u0 = u0list(j);
        for k = 1:2
            op = char(oplist(k));
            symbol = cell2mat(symbollist(k));
            [t1, u1] = Euler_iter(func, inteval, u0, delta_t, op);
            plot(t1, u1, symbol);
            hold on
            grid on
        end
    end
end