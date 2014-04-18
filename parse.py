import xml.sax
class MovieHandler( xml.sax.ContentHandler ):
	def __init__(self):
		self.CurrentData = ""
	 	self.type = ""
	 	self.format = ""
	 	self.year = ""
	 	self.rating = ""
	 	self.stars = ""
	 	self.description = ""
 # Call when an element starts
	def startElement(self, tag, attributes):
		self.CurrentData = tag
 		if tag == "movie":
			print "*****Movie*****"
			title = attributes["title"]
			print "Title:", title
 # Call when an elements ends
 	def endElement(self, tag):
		pass
 # Call when a character is read
 	def characters(self, content):
 		if self.CurrentData == "type":
 			self.type = content
 			print content
 		elif self.CurrentData == "format":
 			self.format = content
 			print content
 		elif self.CurrentData == "year":
 			self.year = content
 			print content
 		elif self.CurrentData == "rating":
 			self.rating = content
 			print content
 		elif self.CurrentData == "stars":
 			self.stars = content
 			print content
 		elif self.CurrentData == "description":
 			self.description = content
 			print content
 

# create an XMLReader
parser = xml.sax.make_parser()
 # turn off namepsaces
parser.setFeature(xml.sax.handler.feature_namespaces, 0)
 # override the default ContextHandler
Handler = MovieHandler()
parser.setContentHandler( Handler )
 
parser.parse("out/dat.xml")

