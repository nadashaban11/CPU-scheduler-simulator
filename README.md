
#  CPU Scheduling Simulator

A clean and simple **CPU Scheduling Simulator** written in C, using a
**linked list** to manage processes.\
This project is designed to help understand core **Operating Systems
scheduling algorithms**.

------------------------------------------------------------------------

## Overview

This simulator allows you to input processes and compute:

-   **Waiting Time**
-   **Turnaround Time**

Currently implemented:

-   ✔ **Add multiple processes**
-   ✔ **Automatic PID assignment**
-   ✔ **Arrival Time / Burst Time / Priority**
-   ✔ **Linked List--based PCB structure**
-   ✔ **FCFS (First-Come, First-Served)**
-   ✔ **Clean and formatted process table**

------------------------------------------------------------------------

## (Implemented)

-   Add multiple processes with:
    -   Arrival Time
    -   Burst Time
    -   Priority
-   Automatic **Process ID assignment**
-   **Linked List** PCB structure\
-   **FCFS Scheduling Algorithm**\
-   Display table including:
    -   PID
    -   Arrival
    -   Burst
    -   Priority
    -   Waiting Time
    -   Turnaround Time

------------------------------------------------------------------------

##  To Do 

  Feature                                       Status
  --------------------------------------------- ------------
  Shortest Job First (SJF) --- Non-preemptive   🔜 Planned
  SJF --- Preemptive                            🔜 Planned
  Priority Scheduling --- Non-preemptive        🔜 Planned
  Priority Scheduling --- Preemptive            🔜 Planned
  Round Robin (user-defined quantum)            🔜 Planned
  Average Waiting Time calculation              🔜 Planned
  Average Turnaround Time calculation           🔜 Planned
  Gantt Chart Output                            🔜 Planned

------------------------------------------------------------------------

## ⚙️ How to Compile & Run

### ✅ 1. Compile

    gcc main.c -o scheduler

### ✅ 2. Run

    ./scheduler

------------------------------------------------------------------------

## 📝 Example Usage

    Enter number of processes: 3

    --- PROCESS 1 ---
    Arrival Time: 0
    Burst Time: 5
    Priority: 2

    --- PROCESS 2 ---
    Arrival Time: 1
    Burst Time: 3
    Priority: 1

    --- PROCESS 3 ---
    Arrival Time: 2
    Burst Time: 8
    Priority: 3

------------------------------------------------------------------------

## 📊 Example Output

    ================== RESULTS ==================

    | PID | Arrival | Burst | Priority | Waiting | Turnaround |
    -----------------------------------------------------------
    |   1 |       0 |     5 |        2 |       0 |          5 |
    |   2 |       1 |     3 |        1 |       4 |          7 |
    |   3 |       2 |     8 |        3 |       7 |         15 |

    ===========================================================

------------------------------------------------------------------------

## 💡 Notes

-   Linked lists allow **dynamic, unlimited** process creation.
-   Sorting by arrival time is **essential** for FCFS/SJF.
-   Future algorithms will reuse the **same PCB structure**.
