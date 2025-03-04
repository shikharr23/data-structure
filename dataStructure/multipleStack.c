#include <stdio.h>
#define MAX 100
int stack[MAX], top1 = -1, top2 = MAX;

int isStack1Empty()
{
    return (top1 == -1) ? 1 : 0;
}
int isStack2Empty()
{
    return (top2 == MAX) ? 1 : 0;
}
int isStack1Full()
{
    return (top1 == top2 - 1) ? 1 : 0;
}
int isStack2Full()
{
    return (top2 == top1 + 1) ? 1 : 0;
}

void push_stack1(int data)
{
    if (isStack1Full())
        printf("Stack1 overflow!!!");

    else
    {
        stack[++top1] = data;
        printf("Element added!!!\n");
    }
}
void push_stack2(int data)
{
    if (isStack2Full())
        printf("Stack2 overflow!!!");

    else
    {
        stack[--top2] = data;
        printf("Element added!!!\n");
    }
}
void pop_stack1()
{
    if(isStack1Empty()) printf("Stack1 underflow!!!\n");

    else
    {
        int val = stack[top1--];
        printf("%d pop from stack1!!\n", val);
    }
}
void pop_stack2()
{
    if(isStack2Empty()) printf("Stack2 underflow!!!\n");

    else
    {
        int val = stack[top2++];
        printf("%d pop from stack2!!!\n", val);
    }
}
void peek_stack1()
{
    if(isStack1Empty()) printf("Stack1 is empty!!!\n");

    else printf("Top element of stack1 id %d\n", stack[top1]);
}
void peek_stack2()
{
    if(isStack2Empty()) printf("Stack2 is empty!!!\n");

    else printf("Top element of stack2 is %d\n", stack[top2]);
}
void display1()
{
    if(isStack1Empty()) printf("Stack1 is empty!!!\n");

    else
    {
        printf("Elements of the stack1 are: ");
        for(int i = top1; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
void display2()
{
    if(isStack2Empty()) printf("Stack2 is empty!!!\n");

    else
    {
        printf("Elements of the stack2 are: ");
        for(int i = top2; i < MAX; i++)
        {
            printf("%d\n", stack[i]);
        }
    }
}




int main()
{
    int data;
	while(1){
		printf("1. Push Stack1\n2. Pop Stack1\n3. Peek Stack1\n4. Show Stack1\n5. Push Stack2\n6. Pop Stack2\n7. Peek Stack2\n8. Show Stack2\n9.Exit\n");
	
		int choice, val;
		printf("Enter choice : ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
            printf("Enter data : ");
            scanf("%d",&data);
				push_stack1(data);
				break;
			case 2:
				pop_stack1();
				
				break;
			case 3:
				peek_stack1();
				break;
			case 4:
				show_stack1();
				break;
			case 5:
            printf("Enter data : ");
            scanf("%d",&data);
				push_stack2(data);
				break;
                case 6:
                pop_stack2();break;
                case 7:
                peek_stack2();break;
                case 8:
                show_stack2();break;
			default:
				printf("Invalid choice !!!!!\n");	
		}
		printf("\n\n");
		system("pause");
	}

    return 0;
}