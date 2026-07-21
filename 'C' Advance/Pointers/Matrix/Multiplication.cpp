#include <iostream>
using namespace std;

int main()
{
    int m,n,s;
    cout <<"\nENTER THE NUMBER FO ROWS AND COLUMNS : ";
    cin >> m >> n ;
    int *A = new int[m*n];

    cout <<"\nenter the elements : ";
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
    { cin>> *(A+i*n+j);}
    }

    cout <<"\nenter a scalar : ";
    cin >> s;

    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++)
    {
        *(A+i*n+j) *= s;
    }
}

    cout <<"new vector : \n";
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
    {
        cout << *(A+i*n+j)<< "  ";
    }
    cout << endl;
    }
    return 0;
}