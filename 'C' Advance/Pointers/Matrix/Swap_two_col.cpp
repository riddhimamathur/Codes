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

    int l,o;
    cout << "Enter two col indices to swap (0-based): ";
    cin >> l >> o;

    for(int i=0;i<m;i++){
        int temp = *(A + l*n + i);
        *(A + l*n + i) = *(A + o*n + i);
        *(A + o*n + i) = temp;
    }

    cout << "Matrix after swapping cols:\n";
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)
            cout << *(A + i*n + j) << " ";
        cout << endl;
    }

return 0;
}
