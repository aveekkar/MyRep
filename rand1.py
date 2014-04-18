str="livin on a prayer"
if(str[5].isspace()):
	print 'yeah space!!!!'
else:
	print 'dhoka!!!'
	
var='some var'
class someclass(object):
	def __init__(self,a):
		self.__a=a
	def showVar(self):
		global var
		var=10
		print var
		
ob=someclass(2)
ob.showVar()
print 'var outside %s'%var

class Parent(object):
	def __init__(self,a):
		self.__a=a
		
	def _meth1(self):
		print 'meth1 in parent'
		
	def shared(self):
		print 'shared in parent'
		
class Child(Parent):
	def __init__(self,a):
		super(Child,self).__init__(a)
		
	def shared(self):
		print 'shared in Child'
		
	def sharedParent(self):
		super(Child,self).shared()

ob1=Child('some crap')
ob1._meth1()
ob1.shared()
ob1.sharedParent()
		


