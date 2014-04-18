import smtplib

sender = 'aveekkar@buffalo.edu'
receivers = ['karmakaraveek123@gmail.com']

message = """From: From Person <aveekkar@buffalo.edu>
To: To Person <karmakaraveek123@gmail.com>
Subject: SMTP e-mail test

This is a test e-mail message.
"""

try:
   smtpObj = smtplib.SMTP('mymint5755')
   smtpObj.sendmail(sender, receivers, message)         
   print "Successfully sent email"
except Exception:
   print "Error: unable to send email"
