#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

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
            char *s1=stack[top--];
            char *s2=stack[top--];
            char s3[100];
            snprintf(s3,100,"(%s%c%s)",s2,ch,s1);
            strcpy(stack[++top],s3);
        }
    }
    char* s=(char*)malloc(strlen(stack[top])+1);
    strcpy(s,stack[top]);
    return s;
}

int main (){
    char exp[100];
    printf("Enter the prefix expression: ");
    gets(exp);
    printf("Infix form of the expression is: %s\n",convertPrefixToInfix(exp));
    return 0;
}
