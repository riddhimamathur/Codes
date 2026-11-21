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
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& a, int left, int mid, int right)
{
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while(i <= mid && j <= right)
    {
        if(a[i] <= a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            temp.push_back(a[j]);
            j++;
        }
    }

    while(i <= mid)
    {
        temp.push_back(a[i]);
        i++;
    }

    while(j <= right)
    {
        temp.push_back(a[j]);
        j++;
    }

    for(int k = 0; k < temp.size(); k++)
    {
        a[left + k] = temp[k];
    }
}

void merge_1(vector<int>& a, int n)
{
    for(int i = 1; i < n; i = i * 2)
    {
        for(int j = 0; j < n - 1; j = j + 2 * i)
        {
            int mid = min(j + i - 1, n - 1);
            int right = min(j + 2 * i - 1, n - 1);

            if(mid < right)
            {
                merge(a, j, mid, right);
            }
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if(n <= 0)
    {
        cout << "Invalid size";
        return 0;
    }

    vector<int> a(n);

    cout << "Enter array elements: ";

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    merge_1(a, n);

    cout << "Sorted Array: ";

    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
