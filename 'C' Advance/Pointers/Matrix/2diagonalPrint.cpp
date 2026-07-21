#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int *A = new int[n*n];
    cout << "Enter elements:\n";
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> *(A + i*n + j);
    cout << "\nDiagonal elements:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j || i + j == n - 1) 
                cout << *(A + i*n + j) << " ";
            else
                cout << "  "; 
        }
        cout << endl;
    }

    delete[] A;
}
