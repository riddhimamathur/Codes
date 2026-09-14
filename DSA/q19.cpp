#include <iostream>
using namespace std;
int findFirst(int A[], int n, int target) {
    int first = -1;
    for (int i = 0; i < n; i++) {
        // check each element
        if (A[i] == target) {
            first = i;   
            break;       
        }
    }
    return first;
}
int findLast(int A[], int n, int target) {
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == target) {
            last = i;
        }
    }
    return last;
}

int main() {
    int n;
    cout <<"\nenter the value of N : ";
    cin >> n;
    
    int A[n];
    cout <<"\nenter the elements : ";
    for (int i=0;i<n;i++)
    {
        cin >> A[i];
    }
    int target ;
    cout <<"\nenter target : ";
    cin >> target;
    int first = findFirst(A, n, target);
    int last = findLast(A, n, target);
    if (first == -1) {
        cout << "Target not found in array." << endl;
    } else {
        cout << "First occurrence of " << target << " = " << first << endl;
        cout << "Last occurrence of " << target << " = " << last << endl;
    }

    return 0;
}
