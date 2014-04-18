def outer(a):
	def inner(b):
		print 'my var %s'%b
		return a
	print 'in outer %s'%a
	return inner

z=outer('maaan!!!!')
print z
print z('oooo!!!!')

def hcf(a,b):
	if(a%b==0):
		return b
	else:
		return hcf(b,a%b)
		
print 'enter two numbers'
num1=int(raw_input('>'))
num2=int(raw_input('>'))
if num1>=num2:
	print 'hcf = %d'%hcf(num1,num2)
else:
	print 'hcf = %d'%hcf(num2,num1)
	
	
def to_bin(a):
	if a==1:
		return str(1)
	else:
		return to_bin(a/2)+str(a%2)
		
print 'enter number to convert to binary'
num=int(raw_input('>'))
s=to_bin(num)
print s
		
