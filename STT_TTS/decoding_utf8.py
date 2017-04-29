import os

current_dir=os.path.dirname(os.path.abspath(__file__))
file_dir=current_dir+'/text_file.ru.txt'
file=open(file_dir,'r',encoding='utf8')
string=file.read()
file.close()
string=string[1:].replace('\n','')
file=open(file_dir,'w')
file.write(string)
file.close()


