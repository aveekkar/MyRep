from sys import argv
import socket
import threading


ip=''
fileName=''


try:
	script,ip,fileName=argv
except:
	print 'Usage: $:-python transfer_client.py <IP_OF_SERVER> <File_To_Download>'


client=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client.connect((ip,10660))


class TransferClient(threading.Thread):
	def __init__(self,name,client):
		super(TransferClient,self).__init__()
		self.__name=name
		self.__client=client
		
	def run(self):
		self.__client.send(fileName)
		size=int(str(self.__client.recv(100)))
		print 'starting download of file size: '+str(size)
		with open(fileName,'wb') as save:
			data=self.__client.recv(1024*1024)
			recsize=len(data)
			while data:
				save.write(data)
				if recsize >= size:
					break
				data=self.__client.recv(1024*1024)
				recsize += len(data)
		self.__client.send('quit')
		self.__client.close()

clientThread=TransferClient('client',client).start()
				
		
