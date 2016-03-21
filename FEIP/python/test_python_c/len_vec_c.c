#include "Python.h"
#include "math.h"
#include <stdlib.h>

// double lenv2(int *list) {
// 	int count = 0;
// 	int i = 1;
// 	for(; i < list[0]; i++) {
// 		count += list[i] * list[i];
// 	}
// 	double result;
// 	result = sqrt(count);
// 	return result;
// }
double lenv2(int list) {
	int count = 0;
	int i = 0;
	for(; i < list; i++) {
		count += i * i;
	}
	double result;
	result = sqrt(count);
	return result;
}

static PyObject * _lenv2(PyObject *self, PyObject *args) {
	// int length = (int)PyList_GET_SIZE(args);
	// int a;
	// PyArg_ParseTuple(PyList_GetItem(args, 200), "i", &a);
	// length = (int)length;
	// int *_list;
	int _list;
	double result;	
	int i = 0;
	// _list = (int*)malloc(sizeof(int) * length + 1);
	// _list[0] = length;
	// for(i = 1; i < length; i++) {
	// 	PyArg_ParseTuple(PyList_GetItem(args, i - 1), "i", _list+i);
	// 	// _list[i] = (int)(PyList_GetItem(args, i - 1));
	// }
	PyArg_ParseTuple(args, "i", &_list);

	result = lenv2(_list);
	return PyFloat_FromDouble(result);
}

static PyMethodDef lenv2Methods[] = {
	{
		"lenv2",
		_lenv2,
		METH_VARARGS,
		""
	},
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef len_vec_c = {
	PyModuleDef_HEAD_INIT,
	"len_vec_c",
	"",
	-1,
	lenv2Methods
};

PyMODINIT_FUNC PyInit_len_vec_c(void) {
	return PyModule_Create(&len_vec_c);
}