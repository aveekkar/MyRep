from sys import argv

try:
	script,string=argv
except:
	string=None
	
def remove(s):
	d=dict()
	l=list()
	ret=''
	for i in range(0,len(s)):
		if d.has_key(s[i]):
			pass
		else:
			d[s[i]]=i
			l.append(s[i])
	for elem in l:
		ret += elem
			
	return ret
		
			
	
		
print remove(string)

