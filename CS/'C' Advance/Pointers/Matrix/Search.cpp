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

    cout << "Enter element to search: ";
    cin >> key;

    bool found = false;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(*(ptr + i*n + j) == key) {
                cout << "Found at position (" << i+1 << "," << j+1 << ")\n";
                found = true;
            }
        }
    }

    if(!found) cout << "Element not found!\n";
return 0;
}
