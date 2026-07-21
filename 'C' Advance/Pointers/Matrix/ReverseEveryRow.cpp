#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows and columns number : ";
    cin >> m >> n;

    int *A = new int[m*n];
    cout << "Enter matrix elements:\n";
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> *(A + i*n + j);

    for(int i=0; i<m; i++) {
        for(int j=0; j<n/2; j++) {
            int temp = *(A + i*n + j);
            *(A + i*n + j) = *(A + i*n + (n-1-j));
            *(A + i*n + (n-1-j)) = temp;
        }
    }

  cout <<"\nnew matrix = ";

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)
            cout << *(A + i*n + j) << " ";
        cout << endl;
    }
    return 0;
}

/* for column reverse 

#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    int *A = new int[m*n];
    cout << "Enter matrix elements:\n";
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> *(A + i*n + j);

    for(int j=0; j<n; j++) {
        for(int i=0; i<m/2; i++) {
            int temp = *(A + i*n + j);
            *(A + i*n + j) = *(A + (m-1-i)*n + j);
            *(A + (m-1-i)*n + j) = temp;
        }
    }

    cout << "Matrix after reversing each column:\n";
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)
            cout << *(A + i*n + j) << " ";
        cout << endl;
    }

    delete[] A;
}
*/