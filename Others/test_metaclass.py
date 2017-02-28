def __init__(self, name):
	self.name = name

cls_dict = {
	'__init__': __init__
}

import types
s = types.new_class('S', (), {}, lambda ns: ns.update(cls_dict))
s.__module__ = __name__
# print(__name__)

class struct_tuple(tuple):
	_fields = []
	def __new__(cls, *args):
		if len(args) != len(cls._fields):
			raise ValueError('of correct type')
		return super().__new__(cls, args)

class a(struct_tuple):
	_fields = ['a', 'v']



sa = a(12, 32)
print(sa.a)