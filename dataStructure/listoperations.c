#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

void insert(int *arr,int *size){ // function to insert an element
int pos,value,i;
printf("Enter position: ");
scanf("%d",&pos);
printf("Enter value: ");
scanf("%d",&value);
pos--;
if(pos>=*size|| pos<0)
printf("Invalid Position !!!\n");
    else{
    for(i = *size;i>pos;i--){
        arr[i]=arr[i-1];
    }
    arr[i]=value;
    (*size)++;
    printf("List Elements Inserted !!!\n");
}
}
void delete(int *arr,int *size){ // Function to delete an element
    int pos,i;
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos<=0|| pos>*size)
    printf("Invalid Position !!!\n");
        else{
        for(i = pos-1;i<=(*size)-1;i++){
            arr[i]=arr[i+1];}
        (*size)--;
        printf("List Elements deleted !!!\n");
    }

}
void search(int *arr, int *size)
{
    int value,i,flag=0;
    printf("Element to search: ");
    scanf("%d", &value);

    for( i = 0; i < size; i++)
    {
        if(value == arr[i])
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        printf("Element found at index: %d\n", i);
    }
    else{
        printf("Element Not found\n");
    }
}


void printArray(int *arr,int n){
    if (n==0)
    printf("List is Empty !!!\n");
    else{
    printf("List Elements are\n");
    for(int i = 0;i<n;i++)
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int main(){
system("cls");
int arr[MAX_SIZE],size;
 printf("Enter the size of array : ");
 scanf("%d",&size);
 printf("Enter elements : ");
 for(int i = 0;i<size;i++){
 scanf("%d",&arr[i]);
 }
 while(1){
 printf("Operation you can use\n");
 printf("1.Insertion \n");
 printf("2.Deletion \n");
 printf("3.Traversing \n");
 printf("4.Searching\n");
 printf("5.Exit\n");
 int choice;
 printf("Enter choice : ");
 scanf("%d",&choice);
 switch (choice){
    case 1:
    insert(arr,&size);
        break;
    case 2:
    delete(arr,&size);
        break;
    case 3:
        printArray(arr,size);
        break;
    case 4:
        search(arr,size);
        break;
    case 5:
        return 0;
        break;
    default :
    printf("Invalid choice\n");
    }
    printf("\n");
    system("pause");
 }
    return 0;
}