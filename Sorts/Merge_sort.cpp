/*
    Merge Sorting : Merge Sort is a divide-and-conquer sorting algorithm
    that sorts an array or list by:

1. Dividing the array into two halves.
2. Recursively sorting each half.
3. Merging the sorted halves into a single sorted array.


TIME COMPLEXITY
Best Case: O(n log n)
Average Case: O(n log n)
Worst Case: O(n log n)

SPACE COMPLEXITY
O(n) (requires extra memory for merging)

ADVATAGES
Stable sorting algorithm.
Efficient for large datasets.
Guarantees O(n log n) performance.

DISADVANTAGES 
Requires additional memory space for merging.
--------------------------------------------------------------------------------
    divide and conquer concept par based hai.
    Idea : 
        1. array ko chote chote parts main divide karte jaate hain.
            (Size = 1),2,4,8,16.....
        2. harek pair ko sort karke merge karte jayange.
        3. step by step size ko increase karte jayenge 1->2->4->8->16....

        Example : [8,3,5,2,9,1]
        Step 1 (Size = 1)
        [8] [3] = [3,8]
        [5] [2] = [2,5]
        [9] [1] = [1,9]

        [3,8,2,5,1,9]
        Step 2 (size = 2)
        [3,8] + [2,5] = [2,3,5,8]
        [1,9] (Same to Same)

        Step 3 : (Size = 4)
        [2,3,5,8] + [1,9] = [1,2,3,5,8,9]

        Important Concept : 
        1. Left Side Sorted hota hai
        2. Right part sorted hota hai
        3. hum keval merge karte jaate hain.

*/
#include <iostream>
using namespace std;
void mergee(int a[],int left, int mid, int right)
{
    // left = 0, mid = 0, right = 1
    int n1 = mid-left+1; //1
    int n2 = right - mid; // 1

    //temp arrays
    int L[n1],R[n2];
    
    //copy data
    for(int i=0;i<n1;i++)
    {
        L[i] = a[left+i];
    }
    for(int j=0;j<n2;j++)
    {
        R[j] = a[mid+1+j];
    }
    //merge logic
    int i=0, j=0,k = left;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k] = L[i];
            i++;
        }
        else 
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    //remaining Elements ko copy karange.
    while(i<n1 )
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }

}
void merge(int a[], int n)
{
    for(int i=1;i<n;i=i*2)
    {
        //left side
        for(int j=0;j<n-1;j=j+2*i)
        {
            int mid = min(j+i-1,n-1);
            int right_end = min(j+2*i-1,n-1);
            mergee(a,j,mid,right_end);
        }
    }
}
void print(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"\n"<<a[i];
    }
}
int main()
{
    int a[] = {8,3,5,2,9,1};
    int n = sizeof(a) / sizeof(a[0]);
    merge(a,n);
    cout<<"\nSorted Array : ";
    print(a,n);
    return 0;

}