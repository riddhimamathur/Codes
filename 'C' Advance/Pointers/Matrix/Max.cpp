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

    // Find maximum element
    int maxElement = *(matrix); 
    for(int i=1; i<m*n; i++) {
        if(*(matrix+i) > maxElement) {
            maxElement = *(matrix+i);
        }
    }

    cout << "Maximum element in matrix = " << maxElement << endl;
    return 0;
}
