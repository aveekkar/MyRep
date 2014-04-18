import re

text = "bbfefbiu [[Category:fvif]] ebfewo [[Category:cuycu]] qwebfi"
lst=re.findall(r'(\[\[Category:(.*?)\]\])',text)
print lst



