/*Create an array using calloc().
Find the largest and second largest elements.
Free the memory.*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,largest,s_largest,n;
    bool hasSecond = false;   
    printf("enter the number of elements : ");
    scanf("%d",&n);
    int *arr = (int*) calloc(n,sizeof(int));
    if (arr == NULL)
    {
        printf("memory allocation failed");
        return 1;
    }

    printf("enter %d elements : ",n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",(arr+i));
    }

    largest = *arr;
    s_largest = *arr;
    for (i = 1; i < n; i++) {
        if (*(arr + i) > largest) {
            s_largest = largest;
            largest = *(arr + i);
            hasSecond = true;
        } else if (*(arr + i) < largest && (!hasSecond || *(arr + i) > s_largest)) {
            s_largest = *(arr + i);
            hasSecond = true;
        }
    }

    printf("Largest element = %d\n", largest);
    if (hasSecond) {
        printf("Second largest element = %d\n", s_largest);
    } else {
        printf("(all elements equal).\n");
    }
    free (arr);
    return 0;
}