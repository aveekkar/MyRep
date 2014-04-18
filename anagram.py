from sys import argv

script,str1,str2=argv

def check_anagram(s1,s2):
	l1=list()
	l2=list()
	for elem in s1:
		l1.append(elem)
		
	for elem in s2:
		l2.append(elem)
		
	l1.sort()
	l2.sort()
	
	if l1==l2:
		print 'true'
	else:
		print 'false'
		
check_anagram(str1,str2)
