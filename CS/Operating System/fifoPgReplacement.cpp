
#include <iostream>
using namespace std;

int main() {
    int i, j, nof, nor, flag = 0;
    int ref[50], frm[50], pf = 0, victim = -1;

    cout << "\n\t FIFO PAGE REPLACEMENT ALGORITHM";

    cout << "\nEnter number of frames: ";
    cin >> nof;

    cout << "Enter number of reference string: ";
    cin >> nor;

    cout << "\nEnter the reference string: ";

    for (i = 0; i < nor; i++)
        cin >> ref[i];

    cout << "\nThe given reference string: ";

    for (i = 0; i < nor; i++)
        cout << ref[i] << " ";

    for (i = 0; i < nof; i++)
        frm[i] = -1;

    cout << "\n";

    for (i = 0; i < nor; i++) {
        flag = 0;

        cout << "\nReference " << ref[i] << " -> ";

        for (j = 0; j < nof; j++) {
            if (frm[j] == ref[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            pf++;
            victim++;
            victim = victim % nof;

            frm[victim] = ref[i];

            for (j = 0; j < nof; j++)
                cout << frm[j] << "\t";
        }
    }

    cout << "\n\nNumber of page faults: " << pf;

    return 0;
}
