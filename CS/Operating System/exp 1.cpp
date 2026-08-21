#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int id[50], at[50], bt[50], ct[50], tat[50], wt[50];
    float total_tat = 0, total_wt = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Process ID: ";
        cin >> id[i];
        cout << "Enter Arrival Time and Burst Time: ";
        cin >> at[i] >> bt[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(id[i], id[j]);
            }
        }
    }

    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < at[i]) {
            current_time = at[i];
        }
        ct[i] = current_time + bt[i];  
        tat[i] = ct[i] - at[i]; 
        wt[i] = tat[i] - bt[i];       

        total_tat += tat[i];
        total_wt += wt[i];

        current_time = ct[i]; 
    }

    // Output Table
    cout << "\nID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << id[i] << "\t" << at[i] << "\t" << bt[i] << "\t"
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    cout << "\nAverage Turnaround Time = " << total_tat / n;
    cout << "\nAverage Waiting Time = " << total_wt / n << endl;

    return 0;
}
