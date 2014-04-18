import platform
import os
import pygame
import time
d=dict(a=1,b=2,c=3)
nd=dict(d.iteritems())
print nd
l1=['apple','bmw','yamaha']
l2=['fruit','car','bike']
l3=zip(l2,l1)
print l3[0][0]

def checkArgs(*a):
    print len(a)
    
checkArgs(1,'aveek','whatever')

print platform.system()+" -- "+platform.release()+" version: "+platform.version()

if(platform.system()=='Linux' or paltform.system()=='Mac'):
    print os.uname()
else:
    print platform.system()+" "+platform.release()
    
print 'Machine   : '+platform.machine()
print 'processor : '+platform.processor()
print 'os        : '+platform.system()
print 'arch      :',
print platform.architecture()
print 'python    : '+platform.python_version()
    


