#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter M & N : ";
    cin >> m >> n;

    int *A = new int[m*n];

    cout << "Enter matrix elements:\n";
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> *(A + i*n + j);

    int x,y;;
    cout << "Enter two row indices to swap (0-based): ";
    cin >> x >> y;

    for(int j=0; j<n; j++) {
        int temp = *(A + x*n + j);
        *(A + x*n + j) = *(A + y*n + j);
        *(A + y*n + j) = temp;
    }

    cout << "Matrix after swapping rows:\n";
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)
            cout << *(A + i*n + j) << " ";
        cout << endl;
    }
return 0;
}
