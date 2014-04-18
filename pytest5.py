import subprocess
process = subprocess.Popen('ls -l',shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
out, err = process.communicate()
if(process.returncode==0):
  print out
else:
  print err

