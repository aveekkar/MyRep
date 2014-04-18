from collections import deque

class Vertex(object):
    def __init__(self,name,lst):
        self._dist=100000
        self._parent=None
        self.color='white'
        self.name=name
        self.lst=lst
        
    def setColor(self,color):
        self.color=color
        
    def getColor(self):
        return self.color
        
    def setDist(self,dist):
        self._dist=dist
        
    def getDist(self):
        return self._dist
        
    def setParent(self,parent):
        self._parent=parent
        
    def getParent(self):
        return self._parent
        
    def getList(self):
        return self.lst
        
    def getName(self):
        return self.name
        
class Graph(object):
    def __init__(self,adjlist,name,source):
        self.adjlist=adjlist
        self.name=name
        self.source=source
        self.count=len(adjlist)
        self.tempcount=0
        
    def searchSource(self):
        for i in self.adjlist:
            if self.source==i[0]:
                return self.adjlist.index(i)
        return -1
                
    def hasNext(self):
        if self.tempcount != self.count:
            return True
        else:
            return False
            
    def next(self):
        if self.tempcount==0:
            l=self.adjlist.pop(self.searchSource())
            self.adjlist.append(l)
            self.tempcount +=1
            return l
        else:
            l=self.adjlist[self.tempcount-1]
            self.tempcount += 1
            return l
                
        

    
    
adlist=list()
src=None
numvert=-1   
    
def getGraph():
    print 'enter no. of vertices'
    try:
       global numvert
       numvert=int(raw_input('>'))
    except:
        print 'please enter a number'
        getGraph()
        
    
    for i in range(0,numvert):
        print 'enter the list'
        inp=str(raw_input(">"))
        temp=inp.split(' ')
        adlist.append(temp)
        
    print 'enter the source of choice'
    global src
    src=str(raw_input('>'))
    
           

        


    
def searchVert(vert,lst):
    if vert==sorc.getName():
        return sorc
    for i in lst:
        if vert==i.getName():
            return i
    return None
    
getGraph()
graph=Graph(adlist,'MyGraph',src)

def BFS():

    if graph.hasNext():
        s=graph.next()
        global sorc
        sorc=Vertex(s[0],s)
        sorc.setColor('grey')
        sorc.setDist(0)
        sorc.setParent(None)
    else:
        raise Exception('Empty Graph')
    

    global vertlist
    vertlist=list()  
    while graph.hasNext():
        utemp=graph.next()
        u=Vertex(utemp[0],utemp)
        vertlist.append(u)
    
    queue=deque([sorc])

    while queue:
        u=queue.popleft()
        for v in u.getList():
            vob=searchVert(v,vertlist)
            if vob.getColor()=='white':
                vob.setParent(u)
                vob.setDist(u.getDist()+1)
                vob.setColor('grey')
                print 'edge from %s to %s'%(u.getName(),vob.getName())
                queue.append(vob)
                u.setColor('black')
        

    print 'for vertex %s parent is %s'%(sorc.getName(),sorc.getParent())
    print 'd[u] is %d'%sorc.getDist()

    for v in vertlist:
        print 'for vertex %s parent is %s'%(v.getName(),v.getParent().getName())
        print 'd[u] is %d'%v.getDist() 

        
spath=list()
def shortestPath(vert):
    spath.append(vert)
    while vert!=src:
        temp=searchVert(vert,vertlist).getParent().getName()
        spath.append(temp)
        vert=temp     

def spth():
    print 'do u also want the shortest path to the node??(y/n)'
    inp=str(raw_input('>'))
    if inp=='y':
        print 'enter the node from which to calculate shortest path'
        inp=(raw_input('>'))
        shortestPath(inp)
        print 'shortest path from %s to %s is'%(inp,src),spath
    else:
        print 'Thank you for using BFS!!! :-D'

BFS()
spth() 


    
