#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    int matrix[m][n];
    cout << "Enter " << m*n << " elements:\n";
    for(int i=0; i<m; i++) 
    {
        for(int j=0; j<n; j++) 
        {
            cin >> matrix[i][j];
        }
    }

    // Sum of each column
    for(int j=0; j<n; j++) 
    {
        int colSum = 0;
        for(int i=0; i<m; i++) 
        {
            colSum += matrix[i][j];
        }
        cout << "Sum of column " << j+1 << " = " << colSum << endl;
    }
    return 0;
}
