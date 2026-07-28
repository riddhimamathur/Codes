
/*Transpose a dynamically allocated matrix.*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c;
    printf("\nEnter the number of rows and columns: ");
    if (scanf("%d %d", &r, &c) != 2 || r <= 0 || c <= 0) {
        printf("Invalid input or dimensions. Please enter two positive integers.\n");
        return 1;
    }

    int* matrix = malloc(r * c * sizeof *matrix);
    if (matrix == NULL) {
        printf("\nMEMORY ALLOCATION FAILED!\n");
        return 1;
    }

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", (matrix + i * c + j));
        }
    }

    int* transpose = malloc(r * c * sizeof *transpose);
    if (transpose == NULL) {
        free(matrix);
        printf("\nMEMORY ALLOCATION FAILED!\n");
        return 1;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            transpose[j * r + i] = matrix[i * c + j];
        }
    }

    printf("\nTranspose of the matrix:\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d ", transpose[i * r + j]);
        }
        printf("\n");
    }

    free(matrix);
    free(transpose);

    return 0;
}
