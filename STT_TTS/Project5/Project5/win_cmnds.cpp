#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<direct.h>
#include<string.h>
#include"command_list.h"
//#include"performer.cpp"

#define cmdow "/cmdow/bin/Release/cmdow.exe "

/*int createlist(int n)
{
    perform* c;
    perform* p=NULL;
    int i;
    for(i=0;i<n;++i)
    {c=(perform*)malloc(sizeof(*c));
     if(!c)
     {return 0;}
    if (i==0)
    {head=c;}
    else
    {p->next=c;}
    p=c;
    c->next=head;
    }
    return 1;
}

void load_list(void)
{
    int a,i=0; 
    perform* c;
    FILE *fpin;
    char file_dir[100];
    char *current_dir;
    current_dir=_getcwd(NULL,0);
    strcpy(file_dir,current_dir);
    strcat(file_dir,"/commands_list.txt");
    fpin=fopen(file_dir,"r");
    if(!fpin)
    {puts("File was not oppened");}
    fscanf(fpin,"%d",&a);
    createlist(a);
    c=head;
    while(++i<=a)
    {fscanf(fpin,"%s%s",&c->order,&c->key_word);
     fgets(c->command,100,fpin);
     c=c->next;
    }
     fclose(fpin);
}*/

int load_list(void)
{
    perform *c, *p=NULL;
    FILE *fpin;
    int i=0;
    char file_dir[100];
    char *current_dir;
    current_dir=_getcwd(NULL,0);
    strcpy(file_dir,current_dir);
    strcat(file_dir,"/commands_list.txt");
    fpin=fopen(file_dir,"r");
    if(!fpin)
    {puts("File was not oppened");}
    while(1)
    {
        c=(perform*)malloc(sizeof(*c));
        if(!c)
        {return 0;}
        fscanf(fpin,"%s%s",&c->order,&c->key_word);
        fgets(c->command,100,fpin);
        if(_stricmp(c->order,"end")!=0)
        {if(head==NULL)
         {head=c;}
         else
         {p->next=c;}
         p=c;
         c->next=head;
         ++i;
        }
        else
        {free(c);
         break;
        }
    }
    fclose(fpin);
    return i;
}   

void win_cmd(char *order, char *key_word)
{
    perform *c;
    char *current_dir;
    char command[200], handle[15], buff[256];
    FILE *cmd;
    current_dir=_getcwd(NULL,0);
    strcpy(command,current_dir);
    strcat(command,cmdow);
    strcat(command,"/T");
    if(!(cmd=_popen(command,"r")))
    {puts("Cmd was not opened");
     exit(1);
    }
    fgets(buff,sizeof(buff),cmd);
    fscanf(cmd,"%s",&handle);
    //printf("%s\n",handle);
    strcpy(command,current_dir);
    strcat(command,cmdow);
    if(_stricmp("window",key_word)==0)
    {strcat(command,handle);
     strcat(command," ");
    }
    if(head==NULL)
    {load_list();}
    c=head;
    while(c)
    {
        if(_stricmp(c->order,order)==0)
        {if(_stricmp(c->key_word,key_word)==0)
         {strcat(command,c->command);
         }
        }
        if(c->next==head)
         {break;}
        c=c->next;    
    }
    _popen(command,"r");      
}

/*int main()
{
    win_cmd("close","window");
}*/
