//BUBBLE SORT

/*bubble sort is a simply sorting algorithm that repeatedly steps through the list, 
  compares adjacent elements and swaps them if they are in the wrong order. The process
  is repeated until the list is sorted.It is called bubble sort because elements tend
  to move up or down like bubbles in water
  
  [4,2,7,1]
  compares 4 and 2, swaps them
  [2,4,7,1]
  compares 4 and 7, no swap
  [2,4,7,1]
  compares 7 and 1, swaps them
  [2,4,1,7]
  repeats the process until the list is sorted
  [1,2,4,7]
  
  
| Case                                          | Time Complexity |
| --------------------------------------------- | --------------- |
| Best Case (already sorted, optimized version) |   O(n)          |
| Average Case                                  |   O(n²)         |
| Worst Case                                    |   O(n²)         |
*/
#include <iostream> 
using namespace std;
int main()
{
    int n;
    cout <<"enter size: ";
    cin>>n;
    int arr[n];
    cout<<"enter elements: ";   
    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<"sorted array: ";
    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
