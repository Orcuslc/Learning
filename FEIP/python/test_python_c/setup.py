from distutils.core import setup, Extension

module1 = Extension('len_vec_c', sources = ['len_vec_c.c'])

setup(name = 'len_vec_c', version = '1.0',
	description = 'len_vec_c',
	ext_modules = [module1])