import os

def list_files(path):
	for line in sorted(os.listdir(path)):    
	    if line.endswith('.c'):
		    print "src/%s \\" % line.strip()
	print "\n"	    
	for line in sorted(os.listdir(path)):    
	    if line.endswith('.cpp'):
		    print "src/%s \\" % line.strip()

list_files('../lib/arduino/src')
list_files('../lib/panstamp/src')