
#include <iostream>
using namespace std;

void priorityScheduling(int n, int bt[], int p[]) {
    int wt[10], tat[10], pid[10];

    for (int i = 0; i < n; i++)
        pid[i] = i + 1;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i] > p[j]) {
                swap(p[i], p[j]);
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    cout << "PID\tBT\tPriority\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        cout << pid[i] << "\t" << bt[i] << "\t"
             << p[i] << "\t\t" << wt[i] << "\t"
             << tat[i] << endl;
    }
}

int main() {
    int n, bt[10], p[10];

    cout << "Enter number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter burst time and priority of P"
             << i + 1 << ": ";
        cin >> bt[i] >> p[i];
    }

    priorityScheduling(n, bt, p);
    return 0;
}
