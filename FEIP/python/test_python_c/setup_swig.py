from distutils.core import setup, Extension

len_vec_swig_module = Extension('_len_vec_swig',
							sources = ['len_vec_swig_wrap.c', 'len_vec_swig.c'],)

setup(name = 'len_vec_swig',
	ext_modules = [len_vec_swig_module],
	py_modules = ["len_vec_swig"],
	)