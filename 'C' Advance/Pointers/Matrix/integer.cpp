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
    int pos = 0, neg = 0, zero = 0;
    for(int i=0; i<m*n; i++)
     {
        if(*(matrix+i) > 0) pos++;
        else if(*(matrix+i) < 0) neg++;
        else zero++;
    }

    cout << "Positive elements = " << pos << endl;
    cout << "Negative elements = " << neg << endl;
    cout << "Zero elements = " << zero << endl;

    delete[] matrix;
}
