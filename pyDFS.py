class Vertex(object):
    def __init__(self,name,adjlist):
        self.name=name
        self.color='white'
        self.time=0
        self.parent=None
        self.stime=0
        self.ftime=0
        adjlist.pop(0)
        self.adjlist=adjlist
        
    def setColor(self,color):
        self.color=color
        
    def getColor(self):
        return self.color
        
    def getName(self):
        return self.name
        
    def setParent(self,parent):
        self.parent=parent
        
    def getParent(self):
        return self.parent
        
    def setSTime(self,time):
        self.stime=time
        
    def getSTime(self):
        return int(self.stime)
        
    def getFTime(self):
        return int(self.ftime)
        
    def setFTime(self,time):
        self.ftime=time
        
    def getTime(self):
        return int(self.time)
        
    def setTime(self,time):
        self.time=time
    
    def getAdj(self):
        return self.adjlist    
        
        
        
vertoblist=list()
vertstrlist=list()

        
def getGraph():
    print 'enter the no. of vertices in the graph'
    global numvert
    numvert=int(raw_input('>'))
    for i in range(0,numvert):
        print 'enter list'
        strtemp=str(raw_input('>'))
        templst=strtemp.split(' ')
        vertstrlist.append(templst)
        
    for i in vertstrlist:
        obtemp=Vertex(i[0],i)
        vertoblist.append(obtemp)
    return vertoblist
    
def search(G,node):
    for i in G:
        if i.getName()==node:
            return i
    return None
    
def DFS(G):
    for u in G:
        if u.getColor()=='white':
            DFS_Visit(u)
            
def DFS_Visit(u):
    u.setColor('grey')
    u.setTime(u.getTime()+1)
    u.setSTime(u.getTime())
    for v in u.getAdj():
        vob=search(vertoblist,v)
        if vob.getColor()=='white':
            vob.setParent(u)
            print 'edge %s -->  %s'%(u.getName(),vob.getName())
            DFS_Visit(vob)
        u.setColor('black')
        u.setTime(u.getTime()+1)
        u.setFTime(u.getTime())
        print 'for %s, d[u]=%d and f[u]=%d'%(u.getName(),u.getSTime(),u.getFTime())
        

DFS(getGraph())        
        
