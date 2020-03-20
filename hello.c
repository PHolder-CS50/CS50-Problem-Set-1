#include <stdio.h>
#include <cs50.h>

// Ask the user their name, and then say hello to them
int main(void)
{
    string usersName = get_string("What is your name? ");
    printf("hello, %s\n", usersName);
}
