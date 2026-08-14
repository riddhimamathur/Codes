/*
Initially allocate space for 5 integers.
Whenever the array becomes full,
increase its size by 5 using realloc() until the user enters -1.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;
    int capacity = 5;   
    int size = 0;       int num;

    arr = (int*)malloc(capacity * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter integers (enter -1 to stop):\n");

    while (1) {
        scanf("%d", &num);

        if (num == -1) {
            break; 
        }

        if (size == capacity) {
            capacity += 5;  
            int *temp = (int*)realloc(arr, capacity * sizeof(int));
            if (temp == NULL) {
                printf("Memory reallocation failed!\n");
                free(arr);
                return 1;
            }
            arr = temp;
        }

        *(arr + size) = num;  
        size++;
    }

    printf("\nFinal array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    free(arr); 
    return 0;
}
