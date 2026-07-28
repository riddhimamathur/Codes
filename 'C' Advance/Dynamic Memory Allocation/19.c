#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows;
    printf("Enter number of rows: ");
    scanf("%d", &rows);

    int* cols = (int*)malloc(rows * sizeof(int));
    int** jagged = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        printf("Enter number of columns for row %d: ", i);
        scanf("%d", &cols[i]);

        jagged[i] = (int*)malloc(cols[i] * sizeof(int));

        printf("Enter elements for row %d:\n", i);
        for (int j = 0; j < cols[i]; j++) {
            scanf("%d", &jagged[i][j]);
        }
    }

    printf("\nJagged Array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols[i]; j++) {
            printf("%d ", jagged[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(jagged[i]);
    }
    free(jagged);
    free(cols);

    return 0;
}
