#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    if(m != n) {
        cout << "Diagonals exist only for square matrices!\n";
        return 0;
    }

    int *A = new int[m*n];
    cout << "Enter matrix elements:\n";
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> *(A + i*n + j);

    cout << "Diagonal elements:\n";
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(i == j || i+j == n-1)
                cout << *(A + i*n + j) << " ";
            else
                cout << "  "; 
        }
        cout << endl;
    }
return 0;
}
