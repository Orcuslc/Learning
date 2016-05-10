function [B] = filtering(B, threshold )
% filter the coefficient matrix with a threshold
% for coeffs in B, if the absolute value of coeff are larger
% than threshold, then set them as 0;
% [row, ~] = size(B);
% result = find(abs(B)>threshold);
% B(result) = 0;
% [row, ~] = size(B);
% for i = 1:row
%     rmax = max(B(i, :));
%     p = find(B(i, :) > threshold * rmax);
%     B(i, p) = 0;
% end

B(1:threshold, :) = 0;