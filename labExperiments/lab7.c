#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
Node *head = NULL;

void insertNodeInBeg(int ele)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = ele;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else
    {
        newNode->next = head;
        head = newNode;
    }
    printf("Node Inserted!!!!\n");
}

void display()
{
    if (head == NULL)
        printf("List is empty!!\n ");
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    while (1)
    {
        printf("-----Singly Linked List-----\n");
        printf("1. Insert Node in Beginning\n");
        printf("2. Insert Node at end\n");
        printf("3. Insert Node at any position\n");
        printf("4. Delete Node from beginning\n");
        printf("5. Delete Node from end\n");
        printf("6. Delete Node from any postion\n");
        printf("7. Search element in list\n");
        printf("8. Sort element\n");
        printf("9. Display list\n");
        printf("10. Exit\n");
        int choice, value;
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertNodeInBeg(value);
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
        case 8:
            /* code */
            break;
        case 9:
            display();
            break;
        case 10:
            exit(0);

        default:
            printf("Invalid choice!!!!\n");
        }
        printf("\n");
    }

    return 0;
}
