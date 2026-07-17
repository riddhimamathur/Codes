#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1,31,27,2,41,38,31,31,31,31};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *p =arr;
    int k = 31;
    int count = 0;
        while ( p < arr+n )
        {
            if (*p == k)
            {
                count = count + 1;
            }
                p++;
            
        }
        cout << "count of k is : " << count ;
        return 0;
    }