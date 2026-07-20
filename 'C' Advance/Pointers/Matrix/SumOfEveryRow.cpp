#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    int *ptr = new int[m*n];   // 1D pointer for matrix

    cout << "Enter " << m*n << " elements:\n";
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> *(ptr + i*n + j);   // pointer arithmetic for input
        }
    }

    // Row sums
    for(int i=0; i<m; i++) {
        int rowSum = 0;
        for(int j=0; j<n; j++) {
            rowSum += *(ptr + i*n + j);   // ith row, jth column
        }
        cout << "Sum of row " << i+1 << " = " << rowSum << endl;
    }

    delete[] ptr;
}

