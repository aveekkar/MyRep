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
    def __init__(self,name,cond,l,n):
        super(Producer,self).__init__()
        self.name=name
        self.cond=cond
        self.l=l
        self.n=n
        
    def run(self):
        self.cond.acquire()
        for i in range(0,int(n)):
           num=random.randint(0,100)
           self.l.append(num)
           print 'generated and appended %d from Thread :- %s'%(num,self.name)
           self.cond.notify()
           time.sleep(1)
        self.l.append('end')
        self.cond.notify()
        self.cond.release()
           
class Consumer(threading.Thread):
    def __init__(self,name,cond,l):
        super(Consumer,self).__init__()
        self.name=name
        self.cond=cond
        self.l=l
        
    def run(self):
        self.cond.acquire()
        while True:
            self.cond.wait()
            if self.l:
                x=self.l.pop()
                if x=='end':
                    print 'exiting from thread :- %s'%self.name
                    break
                print 'received at Thread :- %s the value %d'%(self.name,x)
        self.cond.release()
            
            
            
            
def main():
    condition=threading.Condition()
    l=list()
    prod=Producer('producer',condition,l,n)
    cons=Consumer('consumer',condition,l)
    prod.start()
    cons.start()
    
    
if arg=='run':
    main()
else:
    print 'please enter command run and the number of items to be produced'
    print 'to exit enter Ctrl+z'
    
        
     
