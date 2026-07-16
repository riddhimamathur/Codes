//----METHOD 1----
#include <iostream>
using namespace std;

int sum (int *p, int n)
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
        int a[] = {1,2,3,4,5,6};
        int n = sizeof(a)/sizeof(a[0]);
        cout << "sum is : " << sum (a,n);
        return 0;
    }

    //----------------------Or-----------------------

   /*-----METHOD 2-----
   
    int main()
    {
        int a[] = {1,2,3,4,5,6};
        int *p=a;
        int sum = 0;
        while (p < a + 6)
        {
            sum += *p;
            p++;
        }
        cout << "sum is : " << sum;
    }
      
    one more way is making function like this 
   ----METHOD 3-----
   int sum(int *p, int n)
   {
       int add = 0;
       int *y= p+n;

         while (p < y)
         {
              add += *p;
              p++;
         }
       
       return add;
   }
       int main()
       {
           int a[] = {1,2,3,4,5,6};
           int n = sizeof(a)/sizeof(a[0]);
           cout << "sum is : " << sum (a,n);
           return 0;
       }
   */