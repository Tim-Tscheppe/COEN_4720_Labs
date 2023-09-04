typedef struct
{
    char first_name[100];
    char *last_name;
    char gender;
    int age; // in years;
} USER_RECORD;

void print_hello_message(USER_RECORD *this_user);
char *remove_newline(char *s);
