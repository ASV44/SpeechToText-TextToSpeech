#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<direct.h>
#include<string.h>
//#include"command_list.h"
#include"win_cmnds.cpp"
#include"key_performer.cpp"

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

void cmd_exe(char const *hyp)
{
    perform *c;
    int i=0;
    char command[500];
    char *words[20];
    char text[50];
    char delim[]=" _.,:!?";
    strcpy(text,hyp);
    words[i]=strtok(text,delim);
    while(words[i])
    {
        ++i;
        words[i]=strtok(NULL,delim);
    }
    i=0;
    while(words[i])
    {_strlwr(words[i]);
     //printf("%s ",words[i]);
     ++i;
    }
    if(i<=1)
    {puts("Invalid Command\nPlease Repeat");
     return ;
    }
    if(_stricmp(words[1],"window")==0 || _stricmp(words[1],"windows")==0)
    {win_cmd(words[0],words[1]);
     return ;
    }
    if(head==NULL)
    {load_list();}
    c=head;
    while(c)
    {
        if(_stricmp(c->order,words[0])==0)
        {if(_stricmp(c->key_word,words[1])==0)
         {if(c->command[1]!='0')
          {system(c->command);
           return ;
          }
          else
          {key_perform(c->command);
           return ;
          }
         }
        }
        if(c->next==head)
         {break;}
        c=c->next;
         
    }       
    if(_stricmp(words[0],"open")==0)
    {
        strcpy(command,"start ");
        strcat(command,words[1]);
    }
    if(_stricmp(words[0],"close")==0)
    {
        strcpy(command,"taskkill /F /IM ");
        strcat(command,words[1]);
        strcat(command,".exe");
    }
    
    printf("%s",command);
    system(command);
    
}

/*int main()
{
    char text[]="SOMETHING SSFS";
    cmd_exe(text);
    getch();
}*/
