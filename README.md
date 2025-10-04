# CPU Scheduling Simulation (FCFS, SJF, Round Robin)

This project implements **CPU Scheduling Algorithms** in C++ as part of our Operating Systems coursework.  

- **First Come First Serve (FCFS)** → `fcfs.cpp`
- **Shortest Job First (SJF, Non-Preemptive)** → `sjf.cpp`
- **Round Robin (RR)** → `rr.cpp` (with quantum = 2 or 3)


Run VSCODE:

### 1. Compile
Use `g++` to compile each file:

```bash
g++ fcfs.cpp -o fcfs
g++ sjf.cpp -o sjf
g++ rr.cpp -o rr

Run the executables:

./fcfs
./sjf
./rr


Each processes contains different file in a Folder:

Enter the number of processes.

For each process, enter:

Arrival Time (AT)a

Burst Time (BT)

Example input:

Enter number of processes: 3
Enter arrival time and burst time for each process:
Process 1: 0 5
Process 2: 1 3
Process 3: 2 8

This is based on the format and example given for FCFS, SJF, RR

**Output Format:**

Completion Time (CT)

Turnaround Time (TAT = CT – AT)

Waiting Time (WT = TAT – BT)

Average TAT and WT

Gantt Chart (text-based)


Here is the FCFS FILE:
Process   AT   BT   CT   TAT   WT
P1        0    5    5    5     0
P2        1    3    8    7     4
P3        2    8    16   14    6

Average Turnaround Time = 8.67
Average Waiting Time    = 3.33

Gantt Chart:
| P1 | P2 | P3 |


Shortest Job First (SJF, Non-Preemptive)

Process   AT   BT   CT   TAT   WT
P1        0    5    5    5     0
P2        1    3    8    7     4
P3        2    8    16   14    6

Average Turnaround Time = 8.67
Average Waiting Time    = 3.33

Gantt Chart:
| P1 | P2 | P3 |

it is the same with result as FCFS because P1 always arrives first and runs to complete it.


Round Robin (Quantum = 2)

Process   AT   BT   CT   TAT   WT
P1        0    5    14   14    9
P2        1    3    6    5     2
P3        2    8    16   14    6

Average Turnaround Time = 11.0
Average Waiting Time    = 5.67

Gantt Chart:
| P1 | P2 | P3 | P1 | P3 | P1 | P3 | P3 |

