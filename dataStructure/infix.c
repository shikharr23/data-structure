#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int top1=-1,top2=-1;
char operator[100];
int operand[100];
void doProcess(){
    int x =operand[top1--];
    int y =operand[top1--];
    char opr=operator[top2--];
    int z;
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
    operand[++top1]=z;
}
int precedence(char opr){
    switch(opr){
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
int evalInfixExpression(char *exp){
    int size = strlen(exp);
    for(int i = 0;i<size;i++){
        char ch = exp[i];
        if(isdigit(ch)){
            int num=0;
        while(isdigit(exp[i])){
            num=num*10+exp[i]-48;
            i++;
        }
        i--;
        operand[++top1]=num;
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
            if (top2==-1)
            operator[++top2]=ch;
            else{
                while (top2!=-1 && precedence(ch)<=precedence(operator[top2])){
                doProcess();
                }
                operator[++top2]=ch;
                }

        }
        else if(ch=='('){
            operator[++top2]=ch;
        }
        else if(ch=='('){
            while(operator[top2]!='('){
                doProcess();
            }
            top2--;
        }
    }
        while(top2!=-1){
            doProcess();
        }
        return operand[top1--];
        
    }
       

int main(){
system("cls");
    char str[100];
    printf("Enter Infix Expression : ");
    gets(str);
    int result=evalInfixExpression(str);
    printf("result=%d\n",result);

    return 0;
}