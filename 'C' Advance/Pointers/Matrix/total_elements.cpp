#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cout << "\nENTER THE NUMBER OF ROWS & COLUMNS : ";
    cin >> m >> n;
    int *q = new int[m*n];
    cout << "\nENTER THE ELEMENTS OF MATRIX : \n";
    for (int i = 0; i < m*n; i++)
        {
            cin >> *(q + i);
        }
int count = 0;
int *ptr = q;
while (ptr < q + m*n)
    {
        count++;
        ptr++;
    }
    cout << "\nTOTAL NUMBER OF ELEMENTS : " << count;
    delete[] q; // Free the allocated memory
    return 0;
}