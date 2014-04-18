class A(object):
    x=10;
    def __init__(self,a):
        self.__a=a;
        
    def getVar(self):
        return self.__a
    @staticmethod
    def getStaticVar():
        return A.x
        
        
ob=A('aveek')
print ob.getVar()
print A.x
A.x+=1
ob1=A('simi')
print A.getStaticVar()
print ob1._A__a


def paratest(h='default'):
	print 'value @paratest = %s'%h
	
paratest()
paratest('arg')
