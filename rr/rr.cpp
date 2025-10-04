#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

struct Process {
    int id, at, bt, ct, tat, wt, remaining;
};

int main() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[20];
    for (int i = 0; i < n; i++) {
        cout << "Process " << i+1 << " (AT BT): ";
        cin >> p[i].at >> p[i].bt;
        p[i].id = i+1;
        p[i].remaining = p[i].bt;
    }

    cout << "Enter time quantum: ";
    cin >> quantum;

    queue<int> q;
    int time = 0, completed = 0;
    double totalTAT = 0, totalWT = 0;
    bool inQueue[20] = {false};

    cout << "\nGantt Chart: ";

    
    for (int i = 0; i < n; i++) {
        if (p[i].at == 0) {
            q.push(i);
            inQueue[i] = true;
        }
    }

    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        inQueue[idx] = false;

        
        if (time < p[idx].at) time = p[idx].at;

        cout << "| P" << p[idx].id << " ";
        
        // Execute process
        int exec = min(quantum, p[idx].remaining);
        time += exec;
        p[idx].remaining -= exec;

        
        for (int i = 0; i < n; i++) {
            if (!inQueue[i] && p[i].remaining > 0 && p[i].at <= time) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        // If process finished
        if (p[idx].remaining == 0) {
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            totalTAT += p[idx].tat;
            totalWT += p[idx].wt;
            completed++;
        } else {
            // Not finished, put it back in the queue
            q.push(idx);
            inQueue[idx] = true;
        }
    }
    cout << "|\n";

    // Print result table
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
