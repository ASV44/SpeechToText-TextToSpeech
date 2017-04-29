#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


void text_to_file(char const *text)
{
    FILE *fpin;
    fpin=fopen("text_file.txt","w");
    if(!fpin)
    {puts("File was not opened");}
    fprintf(fpin,"%s",text);
    fclose(fpin);
    fpin=fopen("all_text_file.txt","a");
    if(!fpin)
    {puts("File was not opened");}
    fprintf(fpin,"%s\n",text);
    fclose(fpin);
    return ;
}

