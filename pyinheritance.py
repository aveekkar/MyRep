class A(object):
	a=10
	def meth(self):
		return A.a
		
ob=A()
print ob.meth()
