import numpy
class A(object):
    def __init__(self,a):
        self.__a=a
    def __meth(self):
        return 10
        
ob=A(3)
print ob._A__meth()

print "hello world".split(" ")[0]

print len('hello'*3)
l=[0,1]
print len(l)
d={'a':1,'b':2}
d['c']=3
d['c']=4
for i,v in d.iteritems():
    print str(i)+":"+str(v)+" ",
    
print '\n'

def NaN(num):
    try:
        int(num)
    except:
        try:
            float(num)
        except:
            return True
        else:
            return False
    else:
        return False
    
 
print NaN(4)   
try:
    a=d.get('o',Exception('not present'))
    if NaN(a):
        raise a
except Exception,e:
    print 'Exception: '+str(e)
else:
    print 'found value %d'%a
    

