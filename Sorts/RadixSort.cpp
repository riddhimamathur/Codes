// RADIX SORT : TYPE OF NON COMPARISON SORT 
#include <iostream>
using namespace std;
int getMax(int arr[], int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }    return max;
}
void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);
    for (int place = 1; max / place > 0; place = place * 10)
    {
        int output[100];
        int count[10] = {0};
        for (int i = 0; i < n; i++)
        {
            int digit = (arr[i] / place) % 10;
            count[digit]++;
        }
        for (int i = 1; i < 10; i++)
        {
            count[i] = count[i] + count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int digit = (arr[i] / place) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = output[i];
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    radixSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}