%module len_vec_swig

%{
	#define SWIG_FILE_WITH_INIT
	#include "len_vec_swig.h"
%}

double lenv4(int *vec);