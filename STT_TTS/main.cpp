#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<direct.h>
#include<string.h>
#include"controler.cpp"
#include"text_to_speech.cpp"

int main()
{
    int nm,status;
    char language_in[20],language_out[20];
    char command[500];
    char text[200];
    while(1){
    system("cls");
    puts("\tMenu:");
    puts("1.Speech to text(recording the input text)");
    puts("2.Speech translation");
    puts("3.Commands(executing given commands)");
    puts("4.Text to speech");
    printf("Enter an option:");
    scanf("%d",&nm);
    switch(nm)
    {
        case 1:
            puts("Choose language for input text. Available are English, French, Russian:");
            printf("Language:");
            fflush(stdin);
            gets(language_in);
            command_ctrl(command,language_in,NULL,NULL);
            if(stricmp(language_in,"russian")==0)
            {system("chcp 65001");}
            status=system(command);
            break;
        case 2:
            puts("Choose languages. Available are English, French, Russian:");
            printf("Input Language:");
            fflush(stdin);
            gets(language_in);
            printf("Output Langauge:");
            fflush(stdin);
            gets(language_out);
            command_ctrl(command,language_in,language_out,NULL);
            if(stricmp(language_in,"russian")==0 || stricmp(language_out,"russian")==0)
            {system("chcp 65001");}
            printf("\n%s",command);
            status=system(command);
            break;
        case 3:
            puts("Use English language for input commands");
            command_ctrl(command,"english",NULL,"yes");
            status=system(command);
            break;
        case 4:
            puts("Choose language. Available are English, French, Russian:");
            printf("Language:");
            fflush(stdin);
            gets(language_out);
            while(1)
            {
                system("cls");
                puts("Enter your text:(for return type\"back\")");
                fflush(stdin);
                gets(text);
                if(_stricmp(text,"back")==0)
                {break;}
                speech_text(text,language_out);
            }
            break;
        default:
            puts("You entered incorrect option");
            puts("Press enter to continue");
            getch();
            break;
    }
    }
}
