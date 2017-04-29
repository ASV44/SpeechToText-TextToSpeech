#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<direct.h>

#define translator "/Microsoft_Document_Translator/DocumentTranslatorCmd.exe translatedocuments /documents:"

void translate(char *in_language, char *out_language)
{
    char file[100];
    char command[500];
    char *current_dir;
    int status;
    current_dir=_getcwd(NULL,0);
    strcpy(command,current_dir);
    strcpy(file,current_dir);
    strcat(file,"/text_file.txt /from:");
    if(_stricmp(in_language,"russian")==0)
    {
        strcat(file,"ru");
    }
	if (_stricmp(in_language, "english") == 0)
    {
        strcat(file,"en");
    }
	if (_stricmp(in_language, "french") == 0)
    {
        strcat(file,"fr");
    }
    strcat(file," /to:");
	if (_stricmp(out_language, "russian") == 0)
    {
        strcat(file,"ru");
    }
	if (_stricmp(out_language, "english") == 0)
    {
        strcat(file,"en");
    }
	if (_stricmp(out_language, "french") == 0)
    {
        strcat(file,"fr");
    }
    strcat(command,translator);
    strcat(command,file);
    status=system(command);
}

/*int main()
{
    char language_in[20],language_out[20];
    puts("Languages:");
    fflush(stdin);
    gets(language_in);
    fflush(stdin);
    gets(language_out);
    translate(language_in,language_out);
    getch();
}*/
