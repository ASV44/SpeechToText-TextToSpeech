#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<direct.h>
#include<string.h>

#define russian_model_dir "/pocketsphinx/model/ru-ru/ru "
#define russian_lm_dir "/pocketsphinx/model/ru-ru/ru.lm.bin "
#define russian_dict_dir "/pocketsphinx/model/ru-ru/ru.dict "
#define english_model_dir "/pocketsphinx/model/en-us/en-us "
#define english_lm_dir "/pocketsphinx/model/en-us/en-us.lm.bin "
#define english_dict_dir "/pocketsphinx/model/en-us/cmudict-en-us.dict "
#define french_model_dir "/pocketsphinx/model/fr-fr/fr "
#define french_lm_dir "/pocketsphinx/model/fr-fr/fr.lm.bin "
#define french_dict_dir "/pocketsphinx/model/fr-fr/fr.dict "
#define cmd_dict_dir "/pocketsphinx/model/cmd/cmd.dic "
#define cmd_lm_dir "/pocketsphinx/model/cmd/cmd.lm "

void command_ctrl(char *command, char *language_in, char *language_out, char *cmd)
{
    char *main_dir;
    char language_model[100],language_dict[100],language_lm[100];
    char hmm[100]="-hmm ",lm[100]="-lm ", dict[100]="-dict ";
    int status;
    main_dir=_getcwd(NULL,0);
    strcpy(command,main_dir);
    strcpy(language_model,main_dir);
    strcpy(language_lm,main_dir);
    strcpy(language_dict,main_dir);
    if(cmd!=NULL)
    {
        strcat(language_model,english_model_dir);
        strcat(language_lm,cmd_lm_dir);
        strcat(language_dict,cmd_dict_dir);
    }
    if(stricmp(language_in,"russian")==0)
    {
        strcat(language_model,russian_model_dir);
        strcat(language_lm,russian_lm_dir);
        strcat(language_dict,russian_dict_dir);
    }
    if(stricmp(language_in,"english")==0 && stricmp(language_model,main_dir)==0)
     {
        strcat(language_model,english_model_dir);
        strcat(language_lm,english_lm_dir);
        strcat(language_dict,english_dict_dir);
     }
    if(stricmp(language_in,"french")==0)
     {
        strcat(language_model,french_model_dir);
        strcat(language_lm,french_lm_dir);
        strcat(language_dict,french_dict_dir);
     }
       
    strcat(hmm,language_model);
    strcat(lm,language_lm);
    strcat(dict,language_dict);
    strcat(command,"/Project5/Debug/project5.exe -inmic yes ");
    strcat(command,hmm);
    strcat(command,lm);
    strcat(command,dict);
    if(language_out!=NULL)
    {
        strcat(command,"-translate yes -language_in ");
        strcat(command,language_in);
        strcat(command," -language_out ");
        strcat(command,language_out);
    }
    if(cmd!=NULL)
    {
        strcat(command," -commands yes");
    }
    //status=system("chcp 65001");
    //status=system(command );
}

/*int main()
{
    char command[500],language_in[20],language_out[20],cmd[10];
    puts("Language:");
    fflush(stdin);
    gets(language_in);
    puts("Language:");
    fflush(stdin);
    gets(language_out);
    puts("Commands:");
    fflush(stdin);
    gets(cmd);
    command_ctrl(command,language_in,NULL,cmd);
    printf("\n%s",command);
    getch();
}*/
