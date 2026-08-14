#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    int *A = new int[m*n];
    cout << "Enter matrix elements:\n";
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> *(A + i*n + j);
        }
    }
    int count = 0, sum = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(i == 0 || i == m-1 || j == 0 || j == n-1) {   
                count++;
                sum += *(A + i*n + j);
            }
        }
    }

    cout << "\nBoundary element count = " << count;
    cout << "\nBoundary element sum = " << sum << endl;

    delete[] A;
    return 0;
}
