#include "len_vec_swig.h"
#include "math.h"

double lenv4(int* vec) {
	int length = vec[0];
	int i = 1;
	double count = 0;
	for(; i < length; i++) {
		count += vec[i]*vec[i];
	}
	return sqrt(count);
}

