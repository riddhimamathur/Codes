#include <iostream>
using namespace std;
int main()
{
    int a[]={1,2,31,31,3,4,4,7,9};
    int n = sizeof(a)/sizeof(a[1]);
    int *p = a;
    cout<<"Duplicate elements in the array are: ";
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (*(p+i) == *(p+j))
            {
                cout<<*(p+j)<<" ";
                break;
            }
        }
    }
    cout << endl;
    return 0;
}