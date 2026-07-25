/*Q14.Store product details.
Delete one product and resize memory.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float price;
} Product;

void display(Product *arr, int size) {
    printf("\nProduct List:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d | Name: %s | Price: %.2f\n", arr[i].id, arr[i].name, arr[i].price);
    }
}

int main() {
    int n = 3; 
    Product *arr = (Product*) calloc(n, sizeof(Product));
    arr[0].id = 1; strcpy(arr[0].name, "Shoes"); arr[0].price = 2000.00;
    arr[1].id = 2; strcpy(arr[1].name, "Heels"); arr[1].price = 2500.00;
    arr[2].id = 3; strcpy(arr[2].name, "Gloss"); arr[2].price = 1800.75;

    display(arr, n);
    int delId = 2;
    for (int i = 0; i < n; i++) {
        if (arr[i].id == delId) {
            for (int j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1]; 
            }
            n--; 
            arr = (Product*) realloc(arr, n * sizeof(Product));  
            break;
        }
    }

    printf("\nAfter deletion:\n");
    display(arr, n);

    free(arr);  
    return 0;
}
