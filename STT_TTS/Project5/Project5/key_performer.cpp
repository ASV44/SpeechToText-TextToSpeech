#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include"key_code.h"

#define WINVER 0x0500

int keys_list(void)
{
    key_code *c, *p=NULL;
    FILE *fpin;
    int i=0;
    fpin=fopen("keys_code.txt","r");
    if(!fpin)
    {puts("File was not oppened");}
    while(1)
    {
        c=(key_code*)malloc(sizeof(*c));
        if(!c)
        {return 0;}
        fscanf(fpin,"%s%s",&c->key,&c->code);
        if(_stricmp(c->key,"end")!=0)
        {if(head_key==NULL)
         {head_key=c;}
         else
         {p->next=c;}
         p=c;
         c->next=head_key;
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

void key_press(WORD key)
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk =(WORD)key;
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
}

void key_release(WORD key)
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
    ip.ki.wVk =(WORD)key;
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
}

void key_perform(char *command)
{
    char *keys[20];
    char order[50];
    char delim[]=" _.,:!?";
    int i=0,n;
    _strnset(command,' ',1);
    strcpy(order,command);
    keys[i]=strtok(order,delim);
    while(keys[i])
    {
        ++i;
        keys[i]=strtok(NULL,delim);
    }
    n=0;
    while(keys[n])
    {++n;}
    for(i=0;i<n;++i)
    {key_press(strtol(keys[i],NULL,16));}
    for(i=n-1;i>-1;--i)
    {key_release(strtol(keys[i],NULL,16));}
    //key_press(strtol(num,NULL,16));
    //key_release(strtol(num,NULL,16));

}
