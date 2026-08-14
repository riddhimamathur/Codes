#include <stdio.h>
#include <stdlib.h>

int *arr = NULL;     
int size = 0;        
int capacity = 0;    

void push(int value) {
    if (size == capacity) {
        capacity = (capacity == 0) ? 2 : capacity * 2;
        arr = (int*) realloc(arr, capacity * sizeof(int));
    }
    arr[size] = value;
    size++;
}
void pop() {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    size--;
    printf("Popped: %d\n", arr[size]);
}
void display() {
    if (size == 0) {
        printf("Array is empty!\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void freeArray() {
    free(arr);
    arr = NULL;
    size = 0;
    capacity = 0;
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    push(40);
    push(50);
    display();

    freeArray();
    return 0;
}
