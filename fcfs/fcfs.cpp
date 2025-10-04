#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid; // process ID
    int at;  // arrival time
    int bt;  // burst time
    int ct;  // completion time
    int tat; // turnaround time
    int wt;  // waiting time
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    cout << "Enter Arrival Time (AT) and Burst Time (BT):\n";
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cin >> p[i].at >> p[i].bt;
    }

    
    sort(p.begin(), p.end(), [](Process a, Process b) {
        return a.at < b.at;
    });

    int time = 0;
    vector<string> gantt;
    double totalTAT = 0, totalWT = 0;

    for (int i = 0; i < n; i++) {
        if (time < p[i].at) {
            time = p[i].at; 
        }
        gantt.push_back("P" + to_string(p[i].pid));
        time += p[i].bt;
        p[i].ct = time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        totalTAT += p[i].tat;
        totalWT += p[i].wt;
    }

    cout << "\n===== FCFS Scheduling =====\n";
    cout << "Process\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &pr : p) {
        cout << "P" << pr.pid << "\t" << pr.at << "\t" << pr.bt
             << "\t" << pr.ct << "\t" << pr.tat << "\t" << pr.wt << "\n";
    }

    cout << "Average TAT = " << totalTAT / n << endl;
    cout << "Average WT = " << totalWT / n << endl;

    cout << "Gantt Chart: ";
    for (auto &g : gantt) cout << "| " << g << " ";
    cout << "|\n";

    return 0;
}
