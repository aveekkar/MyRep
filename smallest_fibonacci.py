import math

#code to find the smallest fibonacci number that has a common factor with a given number.
print 'enter the Integer'
try:
	num=int(raw_input('>'))
except:
	print 'Not an Integer'
	
factors=list()
temp=None

# function to factorize
def factorize(n):
	global temp
	r=int(math.ceil(math.sqrt(n)))
	if(r>1):
		for i in range(2,r+1):
			if((n%i)==0):
				factors.append(i)
				n=n/i
				temp=n
				factorize(n)
				break

#Iterator for fibonacci numbers...not checking for has_next() because it will always have a next	
class Fibiter(object):
	def __init__(self):
		self.fib0=1
		self.fib1=1
	def next(self):
		self.fibnext=self.fib0+self.fib1
		self.fib0=self.fib1
		self.fib1=self.fibnext
		return self.fibnext

fib=Fibiter()

#function to find Highest common factor
def hcf(a,b):
	if(a%b==0):
		return b
	else:
		return hcf(b,a%b)
h=1

#keep looping till a match is found...could have used has_next if implemented in the iterator.		
while(True):
	fibconsider=fib.next()
	if(num>fibconsider):
		h=hcf(num,fibconsider)
	else:
		h=hcf(fibconsider,num)
#if hcf is greater than one	then we got our number!!!
	if h>1:
		factorize(h)
		factors.append(temp)
		if(factors[0]==None):
			factors[0]=h
		print 'fib number is %d and least factor is %d'%(fibconsider,factors[0])
		break
	
	
	
	
	

	
