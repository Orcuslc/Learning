% % Test
% format long
% 
% 
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% %                                        For problem (a)
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% 
% [U1, b1] = gen_rand(60);
% [U2, b2] = gen_rand(256);
% [U3, b3] = gen_rand(512);
% [U4, b4] = gen_rand(1024);
% U1 = triu(U1); U2 = triu(U2); U3 = triu(U3); U4 = triu(U4);

% tic
% x11 = row_back_substitute(U1, b1);
% toc
% tic
% x12 = col_back_substitute(U1, b1);
% toc
% tic
% x21 = row_back_substitute(U2, b2);
% toc
% tic
% x22 = col_back_substitute(U2, b2);
% toc
% tic
% x31 = row_back_substitute(U3, b3);
% toc
% tic
% x32 = col_back_substitute(U3, b3);
% toc
% tic
% x41 = row_back_substitute(U4, b4);
% toc
% tic
% x42 = col_back_substitute(U4, b4);
% toc
% x10 = U1\b1; x20 = U2\b2; x30 = U3\b3; x40 = U4\b4;
% u1 = norm(U1); u2 = norm(U2); u3 = norm(U3); u4 = norm(U4);
% norm(x11-x12)/u1
% norm(x11 - x10)/u1
% norm(x12 - x10)/u1
% norm(x21-x22)/u2
% norm(x21 - x20)/u2
% norm(x22 - x20)/u2
% norm(x31-x32)/u3
% norm(x31 - x30)/u3
% norm(x32 - x30)/u3
% norm(x41-x42)/u4
% norm(x41 - x40)/u4
% norm(x42 - x40)/u4

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% For Problem (b)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

[A1, ~] = gen_rand(128); [B1, ~] = gen_rand(128); [C1, ~] = gen_rand(128);
[A2, ~] = gen_rand(256); [B2, ~] = gen_rand(256); [C2, ~] = gen_rand(256);
[A3, ~] = gen_rand(512); [B3, ~] = gen_rand(512); [C3, ~] = gen_rand(512);
[A4, ~] = gen_rand(1024); [B4, ~] = gen_rand(1024); [C4, ~] = gen_rand(1024);
C10 = C1+A1*B1; C20 = C2+A2*B2; C30 = C3+A3*B3; C40=C4+A4*B4;
c1 = norm(C1); c2 = norm(C2); c3 = norm(C3); c4 = norm(C4);
% tic; C11 = mmloop(A1, B1, C1); toc; tic; C12 = mmdot(A1, B1, C1); toc; tic; C13 = mmdaxpy(A1, B1, C1); toc; tic; C14 = mmmatvec(A1, B1, C1); toc; tic; C15 = mmouterdot(A1, B1, C1); toc;
% norm(C11-C10)/c1
% norm(C12-C10)/c1
% norm(C13-C10)/c1
% norm(C14-C10)/c1
% norm(C15-C10)/c1
% tic; C21 = mmloop(A2, B2, C2); toc; tic; C22 = mmdot(A2, B2, C2); toc; tic; C23 = mmdaxpy(A2, B2, C2); toc; tic; C24 = mmmatvec(A2, B2, C2); toc; tic; C25 = mmouterdot(A2, B2, C2); toc;
% norm(C21-C20)/c2
% norm(C22-C20)/c2
% norm(C23-C20)/c2
% norm(C24-C20)/c2
% norm(C25-C20)/c2
% tic; C31 = mmloop(A3, B3, C3); toc; tic; C32 = mmdot(A3, B3, C3); toc; tic; C33 = mmdaxpy(A3, B3, C3); toc; tic; C34 = mmmatvec(A3, B3, C3); toc; tic; C35 = mmouterdot(A3, B3, C3); toc;
% norm(C31-C30)/c3
% norm(C32-C30)/c3
% norm(C33-C30)/c3
% norm(C34-C30)/c3
% norm(C35-C30)/c3
tic; C41 = mmloop(A4, B4, C4); toc; tic; C42 = mmdot(A4, B4, C4); toc; tic; C43 = mmdaxpy(A4, B4, C4); toc; tic; C44 = mmmatvec(A4, B4, C4); toc; tic; C45 = mmouterdot(A4, B4, C4); toc;
norm(C41-C40)/c4
norm(C42-C40)/c4
norm(C43-C40)/c4
norm(C44-C40)/c4
norm(C45-C40)/c4