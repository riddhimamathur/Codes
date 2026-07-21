 #include <iostream>
using namespace std;

int main()
{
    int m,n;
    cout <<"\nENTER THE NUMBER OF ROWS AND COLUMNS : ";
    cin >> m >> n ;
    int *A = new int[m*n];
    int *T = new int[n*m];   //opposite aayega 
    cout <<"\nEnter the elements : ";
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin >> *(A+i*n+j);
        }
    }
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            *(T+j*m+i) = *(A+i*n+j);
        }
    }

    cout <<"\nTranspose Matrix : \n";
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cout << *(T+i*m+j) << " ";
        }
        cout << endl;
    }

   
    return 0;
}
