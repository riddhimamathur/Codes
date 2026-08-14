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
    int sum = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i + j == n - 1) {  
                sum += *(A + i*n + j);
            }
        }
    }
    cout << "\nSum of secondary diagonal = " << sum << endl;
return 0;
}
