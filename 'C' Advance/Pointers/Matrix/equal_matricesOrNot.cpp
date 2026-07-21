#include <iostream>
using namespace std;

int main()
{
    int m,n;
    cout <<"\nEnter value of m and n: ";
    cin >> m >> n;

    int *a = new int[m*n];
    int *b = new int[m*n];

    cout << "\nEnter elements of matrix A:\n";
    for (int i=0; i<m*n; i++) {
        cin >> *(a+i);
    }

    cout << "\nEnter elements of matrix B:\n";
    for (int i=0; i<m*n; i++) {
        cin >> *(b+i);
    }

    bool same = true;  

    for (int i=0; i<m*n; i++) {
        if (*(a+i) != *(b+i)) {  
            same = false; break;
        }
    }

    if (same)
        cout << "Matrices are SAME\n";
    else
        cout << "Matrices are DIFFERENT\n";
    return 0;
}
