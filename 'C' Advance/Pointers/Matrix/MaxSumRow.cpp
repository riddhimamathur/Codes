#include <iostream>
#include <climits>
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

    int maxSum = INT_MIN, rowIndex = -1;
    for(int i=0; i<m; i++) {
        int rowSum = 0;
        for(int j=0; j<n; j++) {
            rowSum += *(ptr + i*n + j);
        }
        if(rowSum > maxSum) {
            maxSum = rowSum;
            rowIndex = i;
        }
    }

    cout << "Row " << rowIndex+1 << " has maximum sum = " << maxSum << endl;

    delete[] ptr;
}
