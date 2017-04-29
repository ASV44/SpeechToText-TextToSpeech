#include<stdio.h>
#include<conio.h>
#include<string.h>

void length_translated(void)
{
    int l;
    char text[100];
    FILE *fpin;
    fpin=fopen("text_file.fr.txt","r");
    fgets(text,100,fpin);
    l=strlen(text);
    printf("\n%d\n",l);
    fclose(fpin);
}
