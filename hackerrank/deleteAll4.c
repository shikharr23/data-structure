#include <stdio.h>

int main()
{
    int size;
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int toDelete;
    scanf("%d", &toDelete);

    // int found = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == toDelete)
        {
            // found = 1;
            for (int j = i; j < size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            size--;
            i--;
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}