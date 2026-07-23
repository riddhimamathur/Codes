/*

Allocate memory for two arrays.
Merge them into a third dynamically allocated array using malloc().

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, n;
    printf("enter the value of m and n: ");
    if (scanf("%d %d", &m, &n) != 2 || m <= 0 || n <= 0)
    {
        printf("Invalid input. Please enter two positive integers.\n");
        return 1;
    }

    int *arr = (int*)malloc(m * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory can't be allocated!\n");
        return 1;
    }

    printf("Enter elements of arr 1: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", arr + i);
    }

    int *arr2 = (int*)malloc(n * sizeof(int));
    if (arr2 == NULL)
    {
        printf("Memory can't be allocated!\n");
        free(arr);
        return 1;
    }

    printf("Enter elements of arr 2: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr2 + i);
    }

    int *arr3 = (int*)malloc((m + n) * sizeof(int));
    if (arr3 == NULL)
    {
        printf("Memory can't be allocated!\n");
        free(arr);
        free(arr2);
        return 1;
    }

    for (int i = 0; i < m; i++)
    {
        arr3[i] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr3[m + i] = arr2[i];
    }

    printf("The new merged array is: ");
    for (int i = 0; i < m + n; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    free(arr);
    free(arr2);
    free(arr3);
    return 0;
}
