
#include <iostream>
using namespace std;

int main() {
    int n, i, j, x;

    cout << "Enter no. of files: ";
    cin >> n;

    int b[20], sb[20], t[20], c[20][20];

    for (i = 0; i < n; i++) {
        cout << "Enter no. of blocks occupied by file "
             << i + 1 << ": ";
        cin >> b[i];

        cout << "Enter the starting block of file "
             << i + 1 << ": ";
        cin >> sb[i];

        t[i] = sb[i];

        for (j = 0; j < b[i]; j++)
            c[i][j] = sb[i]++;
    }

    cout << "\nFilename\tStart block\tLength\n";

    for (i = 0; i < n; i++)
        cout << i + 1 << "\t\t"
             << t[i] << "\t\t"
             << b[i] << endl;

    cout << "\nEnter file name: ";
    cin >> x;

    if (x < 1 || x > n) {
        cout << "Invalid file name!";
        return 0;
    }

    cout << "File name is: " << x << endl;
    cout << "Length is: " << b[x - 1] << endl;

    cout << "Blocks occupied: ";

    for (i = 0; i < b[x - 1]; i++)
        cout << c[x - 1][i] << " ";

    cout << endl;

    return 0;
}
