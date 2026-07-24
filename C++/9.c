//Shrink an integer array after removing all negative numbers using realloc().

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            arr[count++] = arr[i];
        }
    }

    arr = (int*) realloc(arr, count * sizeof(int));
    if (arr == NULL && count > 0) {
        printf("Reallocation failed!\n");
        return 1;
    }

    printf("\nArray after removing negatives:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}

