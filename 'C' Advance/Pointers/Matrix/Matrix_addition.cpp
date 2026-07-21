// Matrix addition of 2 matrices
#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;
    int *A = new int[m*n];
    int *B = new int[m*n];
    int *C = new int[m*n];  
    int *D = new int[m*n];

    cout << "Enter elements of Matrix A:\n";
    for(int i=0; i<m; i++) 
    {
        for(int j=0; j<n; j++) 
        {
            cin >> *(A + i*n + j);
        }
    }
    cout << "Enter elements of Matrix B:\n";
    for(int i=0; i<m; i++) 
    {
        for(int j=0; j<n; j++) 
        {
            cin >> *(B + i*n + j);
        }
    }
    
    for(int i=0; i<m; i++) 
    {
        for(int j=0; j<n; j++)
         {
            *(C + i*n + j) = *(A + i*n + j) + *(B + i*n + j);
         }
    }

    for(int i=0; i<m; i++) 
    {
        for(int j=0; j<n; j++) 
        {
            *(D + i*n + j) = *(A + i*n + j) - *(B + i*n + j);
        }
    }
    cout << "Resultant matrix (A-B):\n";
    for (int i=0; i<m;i++)
    {
        for(int i=0; i<m; i++)
         {
        for(int j=0; j<n; j++)
         {
            cout << *(D + i*n + j) << " ";
        }
        cout << endl;
    }
}
    cout << "Resultant Matrix (A+B):\n";
    for(int i=0; i<m; i++) 
    {
        for(int j=0; j<n; j++) 
        {
            cout << *(C + i*n + j) << " ";
        }
        cout << endl;
    }
    delete[] A;
    delete[] B;
    delete[] C;
    delete[] D;
    return 0;

}

