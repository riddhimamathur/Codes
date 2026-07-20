#include <stdio.h>

int main() {
    int arr[] = {10, 25, 30, 45, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 45;   
    int *p = arr;  
    int found = -1;

    for (int i = 0; i < n; i++) {
        if (*(p + i) == key) {   
            found = i;
            break;
        }
    }

    if (found != -1)
        printf("Element %d found at position %d\n", key, found);
    else
        printf("Element %d not found\n", key);

    return 0;
}
