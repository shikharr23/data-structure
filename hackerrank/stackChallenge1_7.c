#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top1 = -1;

void push(int data)
{
    if (top1 == MAX - 1)
        return;
    else
    {
        int value;
        scanf("%d", &value);
        stack[++top1] = value;
    }
}

void pop()
{
    if (top1 == -1)
        return;
    else
    {
        top1--;
    }
}
void display()
{

    if (top1 == -1)
        return;

    else
    {
        for (int i = top1; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}

int main()
{

    push(90);
    push(12);
    push(56);
    pop(56);
    push(88);
    push(12);
    pop(12);
    pop(88);
    pop(12);
    display();

    return 0;
}
