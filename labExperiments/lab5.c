#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;

    default:
        return -1;
    }
}

// infix to prefix

char *covertInfixtoPrefix(char *exp)
{
    int size = strlen(exp), top = -1, index = 0;
    char operator[size];
    char *str = (char *)malloc(size + 1);
    for (int i = size - 1; i >= 0; i--)
    {
        char ch = exp[i];
        if (isdigit(ch) || isalpha(ch))
            str[index++] = ch;
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            if (top == -1)
                operator[++top] = ch;
            else
            {
                while (top != -1 && precedence(ch) <= precedence(operator[top]))
                {
                    str[index++] = operator[top--];
                }
                operator[++top] = ch;
            }
        }
        else if (ch == ')')
            operator[++top] = ch;
        else if (ch == '(')
        {
            while (operator[top] != ')')
            {
                str[index++] = operator[top--];
            }
            top--;
        }
    }
    while (top != -1)
    {
        str[index++] = operator[top--];
    }
    str[index] = '\0';
    return strrev(str);
}

// infix to postfix

char *covertInfixtoPostfix(char *exp)
{
    int size = strlen(exp), top = -1, index = 0;
    char operator[size];
    char *str = (char *)malloc(size + 1);
    for (int i = 0; i < size; i++)
    {
        char ch = exp[i];
        if (isdigit(ch) || isalpha(ch))
            str[index++] = ch;
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            if (top == -1)
                operator[++top] = ch;
            else
            {
                while (top != -1 && precedence(ch) <= precedence(operator[top]))
                {
                    str[index++] = operator[top--];
                }
                operator[++top] = ch;
            }
        }
        else if (ch == '(')
            operator[++top] = ch;
        else if (ch == ')')
        {
            while (operator[top] != '(')
            {
                str[index++] = operator[top--];
            }
            top--;
        }
    }
    while (top != -1)
    {
        str[index++] = operator[top--];
    }
    str[index] = '\0';
    return str;
}

// postfix to infix

char* convertPostfixToInfix(char* exp)
{
    int size=strlen(exp),top=-1;
    char stack[size][100];
    for(int i=0;i<size;i++)
    {
        char ch=exp[i];
        if(isalnum(ch)){
            char temp[]={ch,'\0'};
            strcpy(stack[++top],temp);
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
        {
            char *s2=stack[top--];
            char *s1=stack[top--];
            char s3[100];
            snprintf(s3,100,"(%s%c%s)",s1,ch,s2);
            strcpy(stack[++top],s3);
        }
    }
    char* s=(char*)malloc(strlen(stack[top])+1);
    strcpy(s,stack[top]);
    return s;
}

// prefix to infix

char* convertPrefixToInfix(char* exp)
{
    int size=strlen(exp),top=-1;
    char stack[size][100];
    for(int i=size-1;i>=0;i--){
        char ch=exp[i];
        if(isalnum(ch))
        {
            char temp[]={ch,'\0'};
            strcpy(stack[++top],temp);
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
        {
            char *s2=stack[top--];
            char *s1=stack[top--];
            char s3[100];
            snprintf(s3,100,"(%s%c%s)",s2,ch,s1);
            strcpy(stack[++top],s3);
        }
    }
    char* s=(char*)malloc(strlen(stack[top])+1);
    strcpy(s,stack[top]);
    return s;
}


int main()
{
    char exp[100];
    printf("Enter Infix expression: "); 
    gets(exp);
    printf("PreFix form of infix Expression %s is %s\n", exp, covertInfixtoPrefix(exp));
    printf("PostFix form of infix Expression %s is %s\n", exp, covertInfixtoPostfix(exp));

    printf("Enter Prefix expression: "); 
    fgets(exp, sizeof(exp), stdin);
    printf("Infix form of Prefix Expression %s is %s\n", exp, convertPrefixToInfix(exp));

    printf("Enter PostFix expression: "); 
    fgets(exp, sizeof(exp), stdin);
    printf("Infix form of PostFix Expression %s is %s\n", exp, convertPostfixToInfix(exp));
    return 0;
}
