function [ values ] = fourier( n, eval_points_x )
%FOURIER �Ժ���f = -1, 0 <= x < pi; f = 1, pi <= x < 2pi ���и���Ҷ�����ƽ��������nΪ�ƽ�����
%�����eval_points_xΪ��ֵ�㣬�����valuesΪ�ƽ���������Щ���ϵ�ֵ

coeff = fourier_coeff( n );
values = fourier_eval( coeff, eval_points_x );


end

