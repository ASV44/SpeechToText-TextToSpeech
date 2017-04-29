typedef struct perform
{
    char order[25];
    char key_word[25];
    char command[100];
    struct perform *next;
}perform;
struct perform *head=NULL;
