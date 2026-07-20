//matrix addition of 2 or more matrices 
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    int *A = new int[m*n];

    int *B = new int[m*n];

    int *C = new int[m*n];  

    cout << "Enter elements of Matrix A:\n";
    for(int i=0; i<m*n; i++) 
    cin >> *(A+i);

    cout << "Enter elements of Matrix B:\n";
    for(int i=0; i<m*n; i++) 
    cin >> *(B+i);

    for(int i=0; i<m*n; i++) {
        *(C+i) = *(A+i) + *(B+i);
    }

    cout << "Resultant Matrix (A+B):\n";
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout << *(C + i*n + j) << " ";
        }
        cout << endl;
    }

    delete[] A; delete[] B; delete[] C;
}
