//SJF IN NON PREEMPTIVE 
#include <iostream>
using namespace std;

void SJF(int n, int at[], int bt[]) {

    int ct[n], tat[n], wt[n];
    bool completed[n] = {false};

    int currentTime = 0;
    int completedCount = 0;

    while (completedCount < n) {

        int shortest = -1;
        int minBT = 9999;
        for (int i = 0; i < n; i++) {

            if (!completed[i] && at[i] <= currentTime) {

                if (bt[i] < minBT) {
                    minBT = bt[i];
                    shortest = i;
                }
            }
        }
        if (shortest == -1) {
            currentTime++;
        }

        else {
            currentTime = currentTime + bt[shortest];

            ct[shortest] = currentTime;

            tat[shortest] = ct[shortest] - at[shortest];

            wt[shortest] = tat[shortest] - bt[shortest];

            completed[shortest] = true;

            completedCount++;
        }
    }
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << endl;
    }
}


int main() {

    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n];

    for (int i = 0; i < n; i++) {

        cout << "Enter Arrival Time of P" << i + 1 << ": ";
        cin >> at[i];

        cout << "Enter Burst Time of P" << i + 1 << ": ";
        cin >> bt[i];
    }

    SJF(n, at, bt);

    return 0;
}