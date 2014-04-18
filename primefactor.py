import math

print 'input number to factorize'
try:
	num=int(raw_input('>'))
except:
	print 'go learn numbers first!!'

factors=list()
temp=None
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

	
factorize(num)
factors.append(temp)
if(factors[0]==None):
	factors[0]=num
print factors
	
		

