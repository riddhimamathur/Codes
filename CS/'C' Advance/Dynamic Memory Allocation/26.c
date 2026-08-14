#include <stdio.h>
#include <stdlib.h>

void insert(int **arr, int *n, int pos, int val) {
    // Increase size by 1
    *arr = (int*)realloc(*arr, (*n + 1) * sizeof(int));
    if (*arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = *n; i > pos; i--) {
        (*arr)[i] = (*arr)[i - 1];
    }
    (*arr)[pos] = val;
    (*n)++;
}

int main() {
    int n = 5;
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize array
    for (int i = 0; i < n; i++) arr[i] = i + 1;

    printf("Original array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    insert(&arr, &n, 2, 99);
    printf("After insertion: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return 0;
}
