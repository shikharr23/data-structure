#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int top=-1;int operand[100];
int evalPostfixExpression(char *exp){
    int size = strlen(exp);
    for (int i = 0;i<size;i++){
        char ch =exp[i];
        if(isdigit(ch)){
            int num=0;
        while(isdigit(exp[i])){
            num=num*10+exp[i]-48;
        
            i++;
        }
        i--;
            operand[++top]=num;
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            int z;
            int x=operand[top--];
            int y=operand[top--];
            char opr=ch;
            switch(opr){
                case '+':
                z=y+x;break;
                case '-':
                z=y-x;break;
                case '*':
                z=y*x;break;
                case '/':
                z=y/x;break;
                case '^':
                z=(int)pow(y,x);break;
            }
            operand[++top]=z;
        }
    }
    return operand[top--];
}
int main(){
    system("cls");
        char str[100];
        printf("Enter Postfix Expression : ");
        gets(str);
        int result=evalPostfixExpression(str);
        printf("result=%d\n",result);
    
        return 0;
    }