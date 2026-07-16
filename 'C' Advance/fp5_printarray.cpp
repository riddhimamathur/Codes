#include <iostream>
using namespace std;

void print(int *p, int n)
{
    for (int i=0;i<n;i++)
    {
        cout << *(p+i) << endl;
    }
}
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9,10};
    print(a,10);
    return 0;
}
