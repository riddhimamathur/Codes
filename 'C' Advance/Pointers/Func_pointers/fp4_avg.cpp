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