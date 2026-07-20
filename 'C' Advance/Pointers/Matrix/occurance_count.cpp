#include <iostream>
using namespace std;

int main() {
    int m, n, key;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    int *ptr = new int[m*n];
    cout << "Enter " << m*n << " elements:\n";
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> *(ptr + i*n + j);
        }
    }

    cout << "Enter number to count: ";
    cin >> key;

    int count = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(*(ptr + i*n + j) == key) count++;
        }
    }

    cout << "Occurrences of " << key << " = " << count << endl;

    delete[] ptr;
}
