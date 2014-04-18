
def pow(a,b):
	result=1;
	while(b!=0):
		if b & 1 == 1:
			result *= a
		b >>= 1
		a *= a
	print result
	
	
inp1=int(raw_input('>'))
inp2=int(raw_input('>'))

pow(inp1,inp2)
