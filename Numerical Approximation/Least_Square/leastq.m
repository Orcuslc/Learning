function [ values_y ] = leastq( points, order, eval_points_x )
%LEASTQ ����������N*2����points, �Լ���ϵĽ���order, ������order <<
%N��,��Ҫ��ֵ��ĺ�����eval_points_x
%   �����ϵĶ���ʽ����Щ���ϵ�ֵvalues_y

coeff_vector = leastq_coeff( points, order );
values_y = leastq_eval( coeff_vector, eval_points_x );

end

