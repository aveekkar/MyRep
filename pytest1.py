import MySQLdb

try:
    db=MySQLdb.connect('localhost','root','alto@5755','MyUse')
    cur=db.cursor()
    cur.execute("Select * from login_details where user_address='Mysore'")
    tup=cur.fetchone()
    while tup is not None:
        print tup
        tup=cur.fetchone()
    db.close
except Exception,e:
    print e
    
    
class Test(object):
    def __init__(self,val1,val2):
        self._val1=val1
        self._val2=val2

l=list()
for i in range(0,10):
    l.append(Test(i,(i*159)%37))
    
#print 'test _val2=&d'%l[0]._Test__val2
    
def comp(x,y):
    if x._val2==y._val2:
        return 0
    elif x._val2>y._val2:
        return 1
    else:
        return -1
        
l.sort(cmp=comp,key=None,reverse=False)

for i in l:
    print i._val2
        

