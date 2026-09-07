#include <iostream>
using namespace std;
int main()
{
    int n;
    cout <<"\nEnter the value of n : ";
    cin >> n;
    int a[n];
    cout << "\nEneter the elements : ";
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int key ;
    int index = -1;
    bool found = false;
    cout <<"\nenter the key : ";
    cin >> key;

    for (int i=0;i<n;i++)
    {
        if (a[i] ==  key)
        {
            found = true;
            cout << "index : " << i;             break;
        }
    }
    if (!found)
    {
        cout << "not found" ;
    }
    return 0;
}