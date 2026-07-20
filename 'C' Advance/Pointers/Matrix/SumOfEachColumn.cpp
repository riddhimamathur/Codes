#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    int *ptr = new int[m*n];   

    cout << "Enter " << m*n << " elements:\n";
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> *(ptr + i*n + j);   
        }
    }
    for(int j=0; j<n; j++) {
        int colSum = 0;
        for(int i=0; i<m; i++) {
            colSum += *(ptr + i*n + j);   /
        }
        cout << "Sum of column " << j+1 << " = " << colSum << endl;
    }

    delete[] ptr;
}
