//count the number of even and odd numbers using pointer
#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(a) / sizeof(a[0]);
    int *ptr = a;
    int evenCount = 0;
    int oddCount = 0;

  while (ptr < a + n) {
            if (*ptr % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
            ptr++;
        }

    cout << "Even numbers: " << evenCount << endl;
    cout << "Odd numbers: " << oddCount << endl;

    return 0;
}