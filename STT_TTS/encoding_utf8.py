import os

current_dir=os.path.dirname(os.path.abspath(__file__))
file_dir=current_dir+'/text_file.txt'
file=open(file_dir,'r',encoding='utf8')
string=file.read()
file.close()
string=string.replace('\n','')
file=open(file_dir,'w',encoding='utf8')
file.write(string)
file.close()
