%test of bezier_interpolation
points = [0, 1, 1, 0; 0, 0, 1, 1];
bezier_interpolation( points );
hold on;
plot( points( 1, : ), points( 2, : ), '*-' );
