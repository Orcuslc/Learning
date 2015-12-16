function[ coeff ]  = fourier_coeff( n )
%对方波：f = -1, 0 <= x < pi; f = 1, pi <= x < 2pi 进行傅里叶级数逼近，输入的n为逼近次数
%输出三角级数的系数矩阵，系数矩阵的第一列为a,第二列为b

%初始化系数矩阵
coeff = zeros( n + 1, 2 );

for i = 2 : n + 1
    if mod( i - 1, 2 ) ~= 0
        coeff( i, 2 ) = -4 / ( i - 1 ) / pi;
    end
end
