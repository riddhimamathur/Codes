/*
    Radix Sorting = yeh ek non comparision sorting hai, jo internally counting sort ka algorithm use main leti hai.

    Yeh numbers ko digit by digit sort karta hai.

    BAsic Idea : 
    1. Sabse pahle sabse choti digit (units place) se sorting start hogi.
    2. uske baad 10's
    3. uske baad 100's
    4. aise jab tam max numbers ke digits khatam nahein ho jaate aage karte rahte hain.

    Examples : 
    [170,45,75,90,802,24,2,66]

    Step 1 : Unit place(1's)

    1's Place Digits
    0,5,5,0,2,4,2,6

    Now Sort : 
    0,0,2,2,4,5,5,6
    [170,90,802,2,24,45,75,66]

    10's 
    7,9,0,0,2,4,7,6
    [0,0,2,4,6,7,7,9]
    [2,802,24,45,66,75,170,90]

    100's
    0,8,0,0,0,0,1,0
    [0,0,0,0,0,0,1,8]
    [2,24,45,66,75,90,170,802]

*/

#include <iostream>
using namespace std;
void countingsort(int a[], int n, int exp)
{
    int outputarray[100]; //result array
    int cnt[10] = {0}; // digits = 0-9
    //count occurance
    for(int i=0;i<n;i++)
    {
        int digit = (a[i]/exp)%10;
        cnt[digit]++;
    }
    // Prefix Sum (position)
    for(int i=1;i<10;i++)
    {
        cnt[i] = cnt[i]+cnt[i-1];
    }
    //Output
    for(int i=n-1;i>=0;i--)
    {
        int digit = (a[i]/exp)%10;
        outputarray[cnt[digit]-1] = a[i];
        cnt[digit]--;
    }

    //Copy BAck
    for(int i=0;i<n;i++)
    {
        a[i] = outputarray[i];
    }
}
void radixsort(int a[], int n)
{
    int max = a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
            max = a[i];
    }
    for(int exp = 1;max/exp>0;exp = exp*10)
    {
        countingsort(a,n,exp);
    }
}
void print(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"\n"<<a[i];
        cout<<endl;
    }
}
int main()
{
    int a[] = {170,45,75,90,802,24,2,66};
    int n = sizeof(a) / sizeof(a[0]);
    radixsort(a,n);
    cout<<"\nAfter Sorting Array is : ";
    print(a,n);
    return 0;
}