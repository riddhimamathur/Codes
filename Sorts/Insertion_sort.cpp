/* Insertion Sort 

Insertion Sort is a simple sorting technique that arranges elements one by one in their correct position within a sorted portion of the array. It works similarly to how people arrange playing cards in their hands.

Algorithm:

1. Assume the first element is already sorted.
2. Take the next element and compare it with previous elements.
3. Insert it into its correct position in the sorted part.
4. Repeat until all elements are sorted.

Example:
Array: 5, 3, 4, 1
After sorting: 1, 3, 4, 5

Advantages:

* Easy to understand and implement.
* Efficient for small datasets.
* Requires no extra memory (in-place sorting).
* Stable sorting algorithm.

Time Complexity:

* Best Case: **O(n)** (already sorted array)
* Average Case: **O(n²)**
* Worst Case: **O(n²)**

Space Complexity: O(1)

Conclusion:
Insertion Sort is suitable for small or nearly sorted arrays due to its simplicity 
and low memory usage.
*/


#include <iostream>
using namespace std;
int main()
{
    int a[] = {5,3,4,1};
    int n = 4;
    // Insertion Sort
    for(int i=1;i<n;i++)
    {
        int key = a[i];
        int j = i-1;

        // Shifting Elements
        while(j>=0 && a[j]>key )
        {
            a[j+1] = a[j];
            j--;
        }

        // insert karange
        a[j+1] = key;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}