#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top1 = -1;

void push(int value)
{
    if (top1 == MAX - 1)
    {
        return;
    }
    else
    {
        stack[++top1] = value;
    }
}

void pop()
{
    if (top1 == -1)
    {

        return;
    }
    top1--;
}

int display()
{

    if (top1 == -1)
        return 0;

    else
    {
        for (int i = top1; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        return 0;
    }
}

int main()
{

    int n;
    scanf("%d", &n);

    // pushing n values

    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        push(value);
    }

    // pop 2 elements;
    pop();
    pop();

    // Push 4 element in the stack

    for (int i = 0; i < 4; i++)
    {
        int value;
        scanf("%d", &value);
        push(value);
    }

    // pop 1 element from the stack

    pop();

    // push 2 element in stack

    for (int i = 0; i < 2; i++)
    {
        int value;
        scanf("%d", &value);
        push(value);
    }

    // pop 3 element from stack

    pop();
    pop();
    pop();

    display();

    return 0;
}
