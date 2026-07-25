
/*Q16.Create an m × n matrix using pointers.

Find :-
Row sum
Column sum
Diagonal sum*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    printf("Enter rows number and column number : ");
    scanf("%d %d", &m, &n);

    int *matrix = (int*) malloc(m * n * sizeof(int));

    printf("Enter elements of the matrix A :\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", (matrix + i*n + j));

    printf("\nMatrix A is :\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", *(matrix + i*n + j));
        printf("\n");
    }
    printf("\nRow sums:\n");
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += *(matrix + i*n + j);
        printf("Row %d sum = %d\n", i+1, sum);
    }
    printf("\nColumn sums:\n");
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++)
            sum += *(matrix + i*n + j);
        printf("Column %d sum = %d\n", j+1, sum);
    }

    if (m == n) {
        int dSum = 0;
        for (int i = 0; i < m; i++)
            dSum += *(matrix + i*n + i);
        printf("\nDiagonal sum = %d\n", dSum);
    }

    free(matrix);
    return 0;
}
