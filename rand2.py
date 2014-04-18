class A(object):
	def __init__(self):
		print 'class A'
		
	def meth(self):
		print 'meth in A'
		
class B(object):
	def __init__(self):
		print 'class B'
		
	def meth(self):
		print 'meth in B'
		
class X(A,B):
	def __init__(self):
		print 'class X'
		
class Y(B,A):
	def __init__(self):
		print 'Class Y'
		
class Z(B,A):
	def __init__(self):
		print 'Class Z'
		

		

ob=X()
ob1=Y()
ob.meth()
ob1.meth()
ob2=Z()
ob2.meth()
