# a simple producer condition problem using event locks...
import threading
import time
import random
from sys import argv
arg=None
n=0
try:
    script, arg,n=argv
except:
    print 'please enter command run and the number of items to be produced'
    print 'to exit enter Ctrl+z'
    exit(0)  



class Producer(threading.Thread):
    def __init__(self,name,cond,l):
        super(Producer,self).__init__()
        self.name=name
        self.cond=cond
        self.l=l
        
    def run(self):
        for i in range(0,int(n)):
           num=random.randint(0,100)
           self.l.append(num)
           self.cond.set()
           print 'generated and appended %d from Thread %s'%(num,self.name)
           time.sleep(1)
           self.cond.clear()
        self.l.append('end')
        self.cond.set()
        time.sleep(1)
        self.cond.clear()
           
class Consumer(threading.Thread):
    def __init__(self,name,cond,l):
        super(Consumer,self).__init__()
        self.name=name
        self.cond=cond
        self.l=l
        
    def run(self):
        while True:
            time.sleep(.00002)
            self.cond.wait()
            if self.l:
                x=self.l.pop()
                if x=='end':
                    print 'exiting from thread :- %s'%self.name
                    break
                print 'received at Thread %s the value %d'%(self.name,x)
 
            
            
            
            
def main():
    condition=threading.Event()
    l=list()
    prod=Producer('producer',condition,l)
    cons=Consumer('consumer',condition,l)
    prod.start()
    cons.start()
    
    
if arg=='run':
    main()
else:
    print 'please enter command run and the number of items to be produced'
    print 'to exit enter Ctrl+z'
    
        
     
