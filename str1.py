from sys import argv
try:
	script, arg=argv
except:
	arg=None
	
print 'input a string'
strng=str(raw_input('>'))

if(len(strng)==0):
	print 'sorry..no string found..do you want to proceed?? [y/n]',
	feedback=str(raw_input())
	if feedback.lower()=='n':
		print 'bye bye'
		exit(0)
	else:
		print 'input a string'
		strng=str(raw_input('>'))

def reverse(s):
	if(len(s)==1):
		return s
	else:
		return reverse(s[1:])+s[0:1]


def palindrome(s):
	if(s==reverse(s)):
		return True
	return False
	

if arg=='sentence':
	lst=reverse(strng).split(' ')
	fnl=''
	for i in lst:
		fnl += reverse(i)+' '
	print fnl[0:len(fnl)-1]
elif arg=='palindrome':
	print palindrome(strng)
else:
	print reverse(strng)
