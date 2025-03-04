#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    
    int N;
    scanf("%d", &N);
    
    int arr[N];
    
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    
   
    
    for(int i = 0; i < N; i++)
    {
         int isUnique = 1;
        for(int j = 0; j < N; j++)
        {
            if(arr[i] == arr[j] && i != j)
            {
                isUnique = 0;
                break;
            }
        }
        
         if(isUnique)
    {
      
            printf("%d ", arr[i]);
            break;
        
     
    }
    }
    
   
    
       
    
    return 0;
}
