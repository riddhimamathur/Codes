//printing only negative elements of an array using pointers

#include <iostream>
using namespace std;
int main()
{
    int x [] ={-1, 2, 31, 4, -5, 6, -7, 8, -9, 10};
    int *p = x;
    cout << "Negative elements in the array are: ";
    while (p < x + 10)
    {
        if (*p < 0)
        {
            cout << *p << " ";
        }
        p++;
    }
    return 0;
}