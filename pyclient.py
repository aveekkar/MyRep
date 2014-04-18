import socket
import threading

client=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client.connect(('localhost',10006))

class Send(threading.Thread):
    def __init__(self,name,client):
        super(Send,self).__init__()
        self._client=client
        self._name=name
        
    def run(self):
        while True:
            txt=str(raw_input('>'))
            if txt=='quit':
                break
            else:
                self._client.send(txt)
                
class Rec(threading.Thread):
    def __init__(self,name,client):
        super(Rec,self).__init__()
        self._name=name
        self._client=client
        
    def run(self):
        while True:
           txt = str(self._client.recv(100))
           if txt=='quit':
               self._client.close()
               break
           print txt
            
sndthrd=Send('send',client).start()
recthrd=Rec('receive',client).start()
