#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int size;
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int toSearch, flag = 0;

    scanf("%d", &toSearch);

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == toSearch)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        printf("Found");
    }

    else
    {
        printf("Not Found");
    }

    return 0;
}
