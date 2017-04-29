typedef struct key_code
{
    char key[50];
    char code[20];
    struct key_code *next;
}key_code;
struct key_code *head_key=NULL;
