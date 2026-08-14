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


    int minElement = *(matrix);  // assume first element is max
    for(int i=1; i<m*n; i++) {
        if(*(matrix+i) < minElement) {
            minElement = *(matrix+i);
        }
    }

    cout << "Minimum element in matrix = " << minElement << endl;

    delete[] matrix;
}
