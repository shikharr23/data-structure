// Lab Experiment 1
#include<stdio.h>
#define MAX_SIZE 100
void insert(int *arr, int *size){
	int pos, value, i;
	printf("Enter Position : ");
	scanf("%d", &pos);
	printf("Enter Value : ");
	scanf("%d", &value);
	if(pos > *size || pos <= 0)
		printf("Invalid Position !!!!\n");
	else{
		for(i=*size; i>=pos; i--){
			arr[i]=arr[i-1];
		}
		arr[pos-1]=value;
		(*size)++;
		printf("Element Inserted !!!\n");
	}
}
void printList(int *arr, int n){
	if(n == 0)
		printf("List is empty !!!\n");
	else{
		int i;
		printf("List Elements are : ");
		for(i=0; i<n; i++){
			printf("%d ", arr[i]);
		}	
	}
}
void delete(int *arr, int *size){
	int pos, i;
	printf("Enter Position : ");
	scanf("%d", &pos);
	if(pos<=0 || pos>*size)
		printf("Invalid position !!!!\n");
	else{
		for(i=pos-1; i<*size-1; i++){
			arr[i]=arr[i+1];
		}
		(*size)--;
		printf("Element Deleted !!!!\n");
	}
}
void search(int *arr, int size){
	int value, i, flag = 0;
	printf("Enter searching element : ");
	scanf("%d", &value);
	for(i=0; i<size; i++){
		if(arr[i]==value){
			flag=1;
			break;
		}
	}
	if(flag == 1)
		printf("Element found at position %d\n",i+1);
	else
		printf("Not Found !!!!\n");
}
int main(){
	int arr[MAX_SIZE], size, i;
	printf("Enter list size : ");
	scanf("%d", &size);
	printf("Enter List Elements : ");
	for(i=0; i<size; i++){
		scanf("%d", &arr[i]);
	}
	printf("For Insertion\n");
				insert(arr, &size);
	printf("For Deletion\n");
				delete(arr, &size);
	printf("For Transversing\n");			
				printList(arr, size);
	printf("\nFor Searching\n");
				search(arr, size);
	return 0;
}