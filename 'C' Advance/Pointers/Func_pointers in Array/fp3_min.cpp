#include <iostream>
using namespace std;
int min(int *p, int n)
{
    int min = *p;
    int *last = p+n;
    while (p<last)
    {
        if (*p < min)
            min = *p;
        p++;
    }
    return min;
};
int main()
{
    int a[] = {1,2,3,4,5,6};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "min is : " << min (a,n);
    return 0;
}