#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<direct.h>
#include<string.h>

void speech_text(char *text, char *language_out)
{
    FILE *fpin;
    int status;
    int voice;
    char *current_dir;
    //current_dir=_getcwd(NULL,0);
    //strcat(current_dir,"/spek.vbs");
    if (_stricmp(language_out, "russian") == 0)
    {
        voice=5;
    }
	if (_stricmp(language_out, "english") == 0)
    {
        voice=0;
    }
	if (_stricmp(language_out, "french") == 0)
    {
        voice=3;
    }
    fpin=fopen("spek.vbs","w");
    if(!fpin)
    {puts("File was not opened");}
    fprintf(fpin,"Dim text, sapi\ntext=\"%s\"\nSet sapi=Createobject(\"sapi.spvoice\")\nwith sapi\nSet.voice=.getvoices.item(%d)\nend with\nsapi.Speak text",text,voice);
    fclose(fpin);
    //printf("\n%s\n",current_dir);
    status=system("spek.vbs");
    return ;
}
    
/*int main()
{
    char text[50];
    puts("Enter text:");
    fflush(stdin);
    gets(text);
    speech_text(text);
    getch();
}*/
