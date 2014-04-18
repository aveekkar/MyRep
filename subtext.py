import re
t=str(raw_input(''))
numwords=int(raw_input(''))
words=list()
for i in range(0,numwords):
    words.append(str(raw_input('')))
    
text=re.sub('(?i)[^A-Z ]','',t).split(' ')
min=0
max=0
count=0
hash1=dict()
for i in words:
	hash1[i]=0
	
hash2=dict()

print hash1

