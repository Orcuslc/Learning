function [ output ] = hermite( x_values, f_values, pf_values, x_series )
%HERMITE Summary of this function goes here
%   Detailed explanation goes here
pos = zeros( 1, length( x_series ) );

%找到x_series每个元素所对应的小区间
for i = 1 : length( x_series )
    pos( i ) = find( x_values >= x_series( i ) , 1, 'first' );
    if pos( i ) == length( x_values )
        pos( i ) = pos( i ) - 1;
    end
end


output = f_values( pos ) + pf_values( pos ) .* ( x_series - x_values( pos ) ) +( ((f_values(pos + 1) - f_values(pos) ) ./ (x_values(pos + 1) - x_values(pos))  - pf_values(pos))) .* ( x_series - x_values(pos) .^ 2) ./ (x_values(pos + 1) - x_values(pos)) + (((pf_values(pos+1) + pf_values(pos)) ./ ((x_values(pos + 1) - x_values(pos)) .^ 2) - 2 .* ((pf_values(pos + 1) - pf_values(pos)) ./ ( (x_values(pos + 1) - x_values(pos)) .^ 3))) .* (( x_series - x_values(pos)) .^ 2) .^ (x_series - x_values(pos)));

end

