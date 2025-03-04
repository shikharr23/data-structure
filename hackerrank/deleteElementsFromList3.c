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

    int toDelete, found = 0;
    scanf("%d", &toDelete);

    int pos = -1, i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == toDelete)
        {
            pos = i;
            break;
        }
    }
    if (pos != -1)
    {
        for (i = pos; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}