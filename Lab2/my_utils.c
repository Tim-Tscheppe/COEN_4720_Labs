#include <stdio.h>
#include <string.h>
#include "my_utils.h"
void print_hello_message(USER_RECORD *this_user)
{
    if (this_user->gender == 'F')
    {
        printf("Hello MRS. %s %s, you are %d years old! \n",
               this_user->first_name, this_user->last_name, this_user->age);
    }
    else if (this_user->gender == 'M')
    {
        printf("Hello MR. %s %s, you are %d years old! \n",
               this_user->first_name, this_user->last_name, this_user->age);
    }
    else
    {
        printf("Hello %s. No soup for you! \n", this_user->first_name);
    }
}
char *remove_newline(char *s)
{
    int len = strlen(s);
    // if there's a newline truncate the string
    if (len > 0 && s[len - 1] == '\n')
    {
        s[len - 1] = '\0';
    }
    return s;
}