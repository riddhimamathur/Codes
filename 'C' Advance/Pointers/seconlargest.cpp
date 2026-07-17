#include <iostream>
using namespace std;
int main() {
    int arr[] = {10, 20, 4, 45, 99, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int *p = arr;   // pointer to array
    int max = *p, second = -1;

    for (int i = 1; i < n; i++) {
        if (*(p+i) > max) {
            second = max;
            max = *(p+i);
        } else if (*(p+i) > second && *(p+i) < max) {
            second = *(p+i);
        }
    }

    printf("Second largest element: %d\n", second);
    return 0;
}
