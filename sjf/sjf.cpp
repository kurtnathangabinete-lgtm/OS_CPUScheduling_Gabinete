#include <iostream>
#include <iomanip>
using namespace std;

struct Process {
    int id, at, bt, ct, tat, wt;
    bool done;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[20];
    for (int i = 0; i < n; i++) {
        cout << "Process " << i+1 << " (AT BT): ";
        cin >> p[i].at >> p[i].bt;
        p[i].id = i+1;
        p[i].done = false;
    }

    int time = 0, completed = 0;
    double totalTAT = 0, totalWT = 0;

    cout << "\nGantt Chart: ";
    while (completed < n) {
        int idx = -1;
        int minBT = 1e9;

        
        for (int i = 0; i < n; i++) {
            if (!p[i].done && p[i].at <= time) {
                if (p[i].bt < minBT) {
                    minBT = p[i].bt;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++; \
            continue;
        }

        
        cout << "| P" << p[idx].id << " ";
        time += p[idx].bt;
        p[idx].ct = time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;

        totalTAT += p[idx].tat;
        totalWT += p[idx].wt;

        p[idx].done = true;
        completed++;
    }
    cout << "|\n";

    // print result table
    cout << "\nProcess  AT  BT  CT  TAT  WT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].id << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].ct << "\t"
             << p[i].tat << "\t"
             << p[i].wt << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time = " << (totalTAT / n);
    cout << "\nAverage Waiting Time    = " << (totalWT / n) << endl;

    return 0;
}
