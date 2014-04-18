import socket
import threading

ser=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
ser.bind(('',10660))
ser.listen ( 10 )

channel,client=ser.accept()
print 'connected to: ',client


class TransferServer(threading.Thread):
	def __init__(self,name,channel):
		super(TransferServer,self).__init__()
		self.__name=name
		self.__channel=channel
		
	def run(self):
		while True:
			txt=str(self.__channel.recv(100))
			if txt is not None:
				print 'from client: '+txt
				if txt == 'quit':
					self.__channel.close()
					ser.close()
					break
				size=450795904
				#with open('out/'+txt,'rb') as f:
					#dat=f.read(1)
					#while dat:
						#size += 1
						#dat=f.read(1)
				print 'file size: '+str(size)+' bytes'
				self.__channel.send(str(size)+'\n')
				with open('out/'+txt,'rb') as transferFile:
					data=transferFile.read(1024*1024)
					while data:
						self.__channel.send(data)
						data=transferFile.read(1024*1024)
			else:
				continue
		
	def search(self,fileName):
		pass
		
serverThread=TransferServer('server',channel).start()	
