#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<direct.h>

void file_speech(char *language_out)
{
    FILE *fpin;
    char text[100];
    char file_name[50],speech_dir[50];
    char *current_dir;
    int l;
    int voice;
    current_dir=_getcwd(NULL,0);
    strcpy(file_name,"text_file.");
	if (_stricmp(language_out, "russian") == 0)
    {
        strcat(file_name,"ru");
        voice=5;
    }
	if (_stricmp(language_out, "english") == 0)
    {
        strcat(file_name,"en");
        voice=0;
    }
	if (_stricmp(language_out, "french") == 0)
    {
        strcat(file_name,"fr");
        voice=3;
    }
    strcat(file_name,".txt");
    fpin=fopen(file_name,"r");
    if(!fpin)
    {puts("File was not opened");}
    fgets(text,100,fpin);
    fclose(fpin);
    //fscanf(fpin,"%s",text);
    printf("%s",text);
    fpin=fopen("spek.vbs","w");
    fprintf(fpin,"Dim text, sapi\ntext=\"%s\"\nSet sapi=Createobject(\"sapi.spvoice\")\nwith sapi\nSet.voice=.getvoices.item(%d)\nend with\nsapi.Speak text",text,voice);
    fclose(fpin);
    strcpy(speech_dir,current_dir);
	strcat(speech_dir, "/spek.vbs");
    system(speech_dir);

}

/*int main()
{
    file_speech();
    getch();

}*/
