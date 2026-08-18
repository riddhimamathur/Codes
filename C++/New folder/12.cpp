#include <iostream>
using namespace std;

int main()
{
    int n;
    int sum = 0;
    cout << "\nEnter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "\nEnter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    cout << "Sum is: " << sum;

    int avg = sum / n;

    cout << "\nAverage: " << avg;

    return 0;
}