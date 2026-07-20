#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    int *matrix = new int[m*n];

    cout << "Enter " << m*n << " elements:\n";
    for(int i=0; i<m*n; i++) {
        cin >> *(matrix+i);
    }

    int sum = 0;
    for(int i=0; i<m*n; i++) 
    {
        sum += *(matrix+i);
    }

    cout << "Sum of all elements = " << sum << endl;
    return 0;
}
