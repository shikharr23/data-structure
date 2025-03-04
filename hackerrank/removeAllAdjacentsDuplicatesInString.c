#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000
int top = -1;
char stack[MAX];

void remove_Duplicates(char *s)
{
    int size = strlen(s);
    for (int i = 0; i < size; i++)
    {
        if (top >= 0 && stack[top] == s[i])
            top--;
        else
        {
            stack[++top] = s[i];
        }
    }
    stack[top + 1] = '\0';
    printf("%s", stack);
}

int main()
{

    char s[MAX];

    scanf("%s", s);
    remove_Duplicates(s);

    return 0;
}