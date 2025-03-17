#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int queue[SIZE], front = -1, rear = -1;

typedef struct PriorityQueue
{
    int element;
    int priority;
} PQueue;

PQueue pq[SIZE];

int isEmpty()
{
    return (front == -1) ? 1 : 0;
}

int isFull()
{
    return (rear == SIZE - 1) ? 1 : 0;
}

void enqueue(int data, int priority)
{
    if (isEmpty())
    {
        rear = rear + 1;
        pq[rear].element = data;
        pq[rear].priority = priority;
        front = rear;
    }
    else
    {
        int i;
        for (i = front; i <= rear; i++)
        {
            if (pq[i].priority < priority)
            {
                for (int j = rear; j >= i; j--)
                {
                    pq[j + 1].element = pq[j].element;
                    pq[j + 1].priority = pq[j].priority;
                }
                pq[i].element = data;
                pq[i].priority = priority;
                rear++;
                break;
            }
        }
        if (i == (rear + 1))
        {
            rear = rear + 1;
            pq[rear].element = data;
            pq[rear].priority = priority;
        }
    }
}

int dequeue()
{
    int data = pq[front].element;
    if(front == rear)
        front = rear = - 1;
    else 
        front = front + 1;
    return data;
}

int peek()
{
    return pq[front].element;
}

void display()
{
    printf("Elements of queue are: \n");
    for (int i = front; i <= rear; i++)
    {
        printf("Element  : %d => Priority : %d\n", pq[i].element, pq[i].priority);
    }
}

int main()
{

    while (1)
    {
        printf("---------PRIORITY QUEUE----------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        int choice, data, p;

        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (isFull())
                printf("Queue Overflow!!\n");
            else
            {
                printf("Enter element: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &p);
                enqueue(data, p);
            }
            break;
        case 2:
            if (isEmpty())
                printf("Queue Underflow!!!\n");
            else
                printf("%d is dequeue from the queue!\n", dequeue());

            break;
        case 3:
            if (isEmpty())
                printf("Priority Queue is empty!!\n");
            else
                printf("Element available in the front of queue is %d\n", peek());
            break;
        case 4:
            if (isEmpty())
                printf("Priority Queue is Empty!!\n");
            else
                display();
            break;
        default:
            printf("Enter a valid choice\n");
        }
        printf("\n");
    }

    return 0;
}
