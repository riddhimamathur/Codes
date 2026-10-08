#include <iostream>
using namespace std;

void roundRobin(int n, int bt[], int tq)
{
    int rem[n], wt[n] = {0}, tat[n];
    
    for(int i = 0; i < n; i++)
        rem[i] = bt[i];

    int time = 0, done = 0;

    while(done < n)
    {
        for(int i = 0; i < n; i++)
        {
            if(rem[i] > 0)
            {
                int x = min(tq, rem[i]);
                time += x;
                rem[i] -= x;

                if(rem[i] == 0)
                {
                    tat[i] = time;
                    wt[i] = tat[i] - bt[i];
                    done++;
                }
            }
        }
    }

    cout << "\nP\tBT\tTAT\tWT\n";
    for(int i = 0; i < n; i++)
        cout << "P" << i+1 << "\t" << bt[i]
             << "\t" << tat[i] << "\t" << wt[i] << endl;
}

int main()
{
    int n, tq;

    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n];

    cout << "Enter burst times: ";
    for(int i = 0; i < n; i++)
        cin >> bt[i];

    cout << "Enter time quantum: ";
    cin >> tq;

    roundRobin(n, bt, tq);

    return 0;
}
