#include <iostream>
using namespace std;

int binarySearch(int *arr, int n, int key) 
{
    int *low = arr;
    int *high = arr + n - 1;
    while(low <= high) {
        int *mid = low + (high - low)/2;
        if(*mid == key) return mid - arr;
        else if(*mid < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() 
{
    int arr[]={2,4,6,8,10};
    int n=5;
    int key=8;
    int idx = binarySearch(arr,n,key);
    if(idx!=-1) cout<<"Found at index "<<idx;
    else cout<<"Not found";
    return 0;
}
