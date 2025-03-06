#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *convertPostfixToinfix(char *exp)
{
    int size = strlen(exp), top = -1;
    char stack[size][100];
    for (int i = 0; i < size; i++)
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
            char temp[100];
            snprintf(temp, 100, "(%s%c%s)", s2, ch, s1);
            strcpy(stack[++top], temp);
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
    printf("Infix form of Postfix form %s is %s", exp, convertPostfixToinfix(exp));
    return 0;
}
