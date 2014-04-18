import MySQLdb
from sys import argv


fileName=None
try:
	script,fileName=argv
except:
	print "Usage: python sqlquiz.py dataFileName"

def populate(dataFile):
	print 'starting...'
	db=MySQLdb.connect('localhost','root','alto@5755','mydb')
	cur=db.cursor()
	sqlstring=""
	for string in open(dataFile):
		sqlstring += string+" "
		print 'SQLSTRING: - '+sqlstring
		if string.startswith('--'):
			sqlstring=""
			continue
		elif string[-1:]!=';':
			continue
		else:
			try:
				print 'executing: '
				print sqlstring
				cur.execute(sqlstring)
			except Exception,e:
				print e
	db.close()

if fileName is not None:
	populate(fileName)
else:
	print "Usage: python sqlquiz.py dataFileName"
    		
	
