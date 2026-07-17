#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 2, 3, 4, 5, 2, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *p = arr;

    cout << "Unique elements: ";
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < n; j++) {
            if (i != j && *(p+i) == *(p+j)) {
                isDuplicate = true;
                break;
            } }
        if (!isDuplicate) {
            cout << *(p+i) << " ";
        }
    }
    return 0;
}
