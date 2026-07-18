#include <iostream>
using namespace std;

void selectionSort(int *arr, int n) {
    for(int i=0;i<n-1;i++) {
        int *minPtr = arr+i;
        for(int j=i+1;j<n;j++) {
            if(*(arr+j) < *minPtr) {
                minPtr = arr+j;
            }
        }
        int temp = *(arr+i);
        *(arr+i) = *minPtr;
        *minPtr = temp;
    }
}
void print(int *arr, int n) {
    for(int i=0;i<n;i++) {
        cout << *(arr+i) << " ";
    }
    cout << endl;
}

int main() {
    int arr[]={64,25,12,22,11};
    int n=5;
    selectionSort(arr,n);
    print(arr,n);
    return 0; 
}
