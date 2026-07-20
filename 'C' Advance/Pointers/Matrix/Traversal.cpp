#include <iostream>
using namespace std;

int main()
{
    int m[3][3];
    int *p = &m[0][0];
    cout << "enter nine elements : \n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> *(p + i * 3 + j);
        }
    }
cout << "matrix : ";
for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << *(p + i * 3 + j) << " ";
        }
        cout << endl;
    }
    return 0;
}