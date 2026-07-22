#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i;
    printf("Enter size of array (N): ");
    scanf("%d", &N);

    int *arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nEnter the elements: ");
    for (i = 0; i < N; i++) {
        scanf("%d", &arr[i]);   // fixed scanf
    }

    printf("\nOnly even numbers: ");
    for (i = 0; i < N; i++) {
        if (arr[i] % 2 == 0) {   // check even number
            printf("%d ", arr[i]);
        }
    }

    printf("\nArray in reverse order:\n");
    for (i = N - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
