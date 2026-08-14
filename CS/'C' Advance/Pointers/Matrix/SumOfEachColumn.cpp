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

    // Column sums
    for(int j=0; j<n; j++) {
        int colSum = 0;
        for(int i=0; i<m; i++) {
            colSum += *(ptr + i*n + j);   // ith row, jth column
        }
        cout << "Sum of column " << j+1 << " = " << colSum << endl;
    } return 0;
}
