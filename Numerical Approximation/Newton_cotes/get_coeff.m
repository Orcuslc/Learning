function[ coeff ] = get_coeff( order )
% get_coeff of newton_cotes formula of interval
% order means the order of the formula
switch order
    case 1
        coeff = [1, 1];
    case 2
        coeff = [1, 4, 1];
    case 3
        coeff  = [1,3,3,1];
    case 4
        coeff = [7,32, 12, 32, 7];
    case 5
        coeff = [19, 75, 50, 50, 75, 19];
    case 6
        coeff = [41, 216, 27, 272, 27, 216, 41];
    case 7
        coeff = [751, 3577, 1323, 2989, 2989, 1323, 3577, 751];
    case 8
        coeff = [989, 5888, -928, 10496, -4540, 10496, -928, 5888, 989];
    otherwise
        error('order should be between 0 and 8 --get_cotes_coeff');
end
    coeff = coeff / sum(coeff);