#include <iostream>
using namespace std;
int main()
{
    int a[]={12,34,35,45};
    int *p=a;
    int sum=0;
    while (p<a+4)
    {
        sum+=*p;
        p++;
    }
    cout<<"avg is : "<<sum/4;
    return 0;
}
 

/*--------or--------
int sum(int *p, int n)
{
    int add = 0;
    for (int i=0; i<n; i++)
    {
            add += *(p + i);
        }
    return add;
};
    int main()
    {
        int a[] = {12,34,35,45};
        int n = sizeof(a)/sizeof(a[0]);
        cout << "avg is : " << sum (a,n)/n;
        return 0;
    }
        */