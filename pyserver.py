import socket
import threading

ser=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
ser.bind(('',10006))
ser.listen ( 10 )

channel,client=ser.accept()
print 'connected to',client

class Send(threading.Thread):
    def __init__(self,name,channel):
        super(Send,self).__init__()
        self._name=name
        self._channel=channel
        
    def run(self):
        while True:
            txt=str(raw_input('>'))
            if txt=='quit':
                print 'you are quitting the server'
                self._channel.send(txt)
                self._channel.close()
                ser.close()
                break
            else:
                self._channel.send(txt)
       
       
class Rec(threading.Thread):
    def __init__(self,name,channel):
        super(Rec,self).__init__()
        self._name=name
        self._channel=channel
        
    def run(self):
        while True:
            txt=str(self._channel.recv(100))
            if txt=='quit':
                self._channel.close()
                break
            print txt
            
            

sendthrd=Send('send',channel).start()
recthrd=Rec('receive',channel).start()

        
