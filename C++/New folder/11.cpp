#include <iostream>
using namespace std;

int factorial (int a)
{   int fact = 1;
        for (int i=a;i>=1;i--)
        {
            fact *= i;
        }
    cout << "factorial = " << fact << endl;
    return fact;
}
int main()
{
    int n ;
    cout <<"enter the value of n : ";
    cin >> n;
    factorial(n);
    return 0;
}