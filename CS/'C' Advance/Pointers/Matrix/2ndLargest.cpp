#include <iostream>
#include <climits>
using namespace std;

int main() {
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    int *ptr = new int[m*n];
    cout << "Enter " << m*n << " elements:\n";
    for(int i=0; i<m*n; i++) {
        cin >> *(ptr+i);
    }

    int largest = INT_MIN, secondLargest = INT_MIN;
    for(int i=0; i<m*n; i++) {
        int val = *(ptr+i);
        if(val > largest) {
            secondLargest = largest;
            largest = val;
        } else if(val > secondLargest && val < largest) {
            secondLargest = val;
        }
    }

    if(secondLargest == INT_MIN)
        cout << "No second largest element (all elements same).\n";
    else
        cout << "Second largest element = " << secondLargest << endl;

    delete[] ptr;
}
