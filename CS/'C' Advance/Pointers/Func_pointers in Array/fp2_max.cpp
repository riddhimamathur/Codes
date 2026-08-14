#include <iostream>
using namespace std;
int max(int *p, int n)
{
    int max = *p;
    int *last = p+n;
    while (p<last)
    {
        if (*p > max)
            max = *p;
        p++;
    }
    return max;
};
int main()
{
    int a[] = {1,2,3,4,5,6};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "max is : " << max (a,n);
    return 0;
}