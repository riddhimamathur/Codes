/*Allocate memory for an array.
Remove all duplicate elements without creating another array.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *arr;
    int i, j, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int*)calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", (arr + i));
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (*(arr + i) == *(arr + j)) {
              
                for (k = j; k < n - 1; k++) {
                    *(arr + k) = *(arr + k + 1);
                }
                n--;     
                j--;   
            }
        }
    }

    printf("\nArray after removing duplicates:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    free(arr);
    return 0;
}
