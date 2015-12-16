function[ coeff ]  = fourier_coeff( n )
%�Է�����f = -1, 0 <= x < pi; f = 1, pi <= x < 2pi ���и���Ҷ�����ƽ��������nΪ�ƽ�����
%������Ǽ�����ϵ������ϵ������ĵ�һ��Ϊa,�ڶ���Ϊb

%��ʼ��ϵ������
coeff = zeros( n + 1, 2 );

for i = 2 : n + 1
    if mod( i - 1, 2 ) ~= 0
        coeff( i, 2 ) = -4 / ( i - 1 ) / pi;
    end
end
