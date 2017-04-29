import os

current_dir=os.path.dirname(os.path.abspath(__file__))
file_dir=current_dir+'/text_file.en.txt'
file=open(file_dir,'r')
string=file.read()
file.close()
string=string.replace('\n','')
file=open(file_dir,'w')
file.write(string)
file.close()
