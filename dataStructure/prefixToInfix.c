#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *convertPrefixToinfix(char *exp)
{
    int size = strlen(exp), top = -1;
    char stack[size][100];
    for (int i = size - 1; i >= 0; i--)
    {
        char ch = exp[i];
        if (isalnum(ch))
        {
            char temp[] = {ch, '\0'};
            strcpy(stack[++top], temp);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            char *s1 = stack[top--];
            char *s2 = stack[top--];
            char s3[100];
            snprintf(s3, 100, "(%s%c%s)", s1, ch, s2);
            strcpy(stack[++top], s3);
        }
    }
    char *s = stack[top];
    return s;
}

int main()
{
    char exp[100];
    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);
    printf("Infix form of Prefix form %s is %s", exp, convertPrefixToinfix(exp));
    return 0;
}
