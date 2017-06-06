function [ result ] = newton_cotes( func, inteval, order )
%NEWTON_COTES 采用Newton-Cotes公式计算积分的近似值
%其中func为被积函数，inteval为积分区间，表示为一个1*2的向量，order为N-C公式的阶数
%author: chuanlu@2015.11.19

if nargin < 2
    error(' Too few inputted arguments, please check if function and inteval for integrating have been inputted or not  -- Newton_Cotes');
elseif nargin == 2
    order = 2;
    % 这里，我们认为默认条件下，采用Simpson公式
end

% if order < 0 || order > 8
%     error(' Order Error: The order should be between 0 and 8. --Newton_Cotes ');
% end

low = inteval( 1 );
high = inteval( 2 );

if order == 0
    result = feval(func, (low + high) / 2) * (high - low);
else
%     coeff = zeros(8, 9);
%     %coeff为8行9列的系数矩阵，行号为order，列号为每一个order对应的系数向量
% 
%     %初始化coeff
%     coeff(1, 1 : 2) = [1,1] / 2;
%     coeff(2, 1 : 3) = [1,4,1] / 6;
%     coeff(3, 1 : 4) = [1,3,3,1] / 8;
%     coeff(4, 1 : 5) = [7,32,12,32,7] / 90;
%     coeff(5, 1 : 6) = [19,75,50,50,75,19] / 288;
%     coeff(6, 1 : 7) = [41,216,27,272,27,216,41] / 840;
%     coeff(7, 1 : 8) = [751,3577,1323,2989,2989,1323,3577,751] / 17280;
%     coeff(8, 1 : 9) = [989,5888,-928,10496,-4540,10496,-928,5888,989] / 28350;
    coeff = get_coeff(order);

    eval_points = low : (high - low) / order : high;
    eval_points = transpose( eval_points );
    result = sum( coeff * feval(func, eval_points)) * (high - low);
%     coeff = cotes_coefficient(order);
%    coeff = new_cotes_coefficient(order);
%      result = sum(transpose(coeff) * func(eval_points)) *( high - low );
end