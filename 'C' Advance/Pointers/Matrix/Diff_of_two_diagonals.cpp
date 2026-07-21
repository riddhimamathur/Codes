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

    int Sum1 = 0, Sum2 = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) {                 
                Sum1 += *(A + i*n + j);
            }
            if(i + j == n - 1) {         
                Sum2 += *(A + i*n + j);
            }
        }
    }

    cout << "\nMain diagonal sum = " << Sum1;
    cout << "\nSecondary diagonal sum = " << Sum2;
    cout << "\nDifference = " << Sum1 - Sum2 << endl;

    delete[] A;
}
