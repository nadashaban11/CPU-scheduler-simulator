#include <stdio.h>
#include <stdlib.h>

int idCnt = 0;

struct PCB {
    int pId;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnarround_time;
    struct PCB* next;
};

void insertProcess(struct PCB** head, struct PCB* newProcess);
void processes_sort(struct PCB* head);
void FCFS(struct PCB* head);
void printProcesses(struct PCB* head);


int main() {
    printf("=== WELCOME TO CPU SCHEDULING SIMULATOR ===\n");

    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct PCB* head = NULL;

    for (int i = 0; i < n; i++) {
        printf("\n--- PROCESS %d ---\n", i + 1);

        struct PCB* newProcess = (struct PCB*)malloc(sizeof(struct PCB));

        printf("Enter Arrival Time: ");
        scanf("%d", &newProcess->arrival_time);

        printf("Enter Burst Time: ");
        scanf("%d", &newProcess->burst_time);

        printf("Enter Priority: ");
        scanf("%d", &newProcess->priority);

        newProcess->waiting_time = 0;
        newProcess->turnarround_time = 0;
        newProcess->next = NULL;
        newProcess->pId = ++idCnt;

        insertProcess(&head, newProcess);
    }

    // ---------- Choose Algorithm ----------
    int choice;
    printf("\nChoose Scheduling Algorithm:\n");
    printf("1. FCFS\n");
    printf("2. SJF (Coming Soon)\n");
    printf("3. Priority Scheduling (Coming Soon)\n");
    printf("4. Round Robin (Coming Soon)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            FCFS(head);
            break;
        default:
            printf("\nAlgorithm not implemented yet.\n");
            return 0;
    }

    printf("\n=== RESULTS ===\n");
    printProcesses(head);

    return 0;
}



// ------------------ Insert Process ------------------
void insertProcess(struct PCB** head, struct PCB* newProcess) {
    if (*head == NULL) {
        *head = newProcess;
        return;
    }
    struct PCB* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newProcess;
}


// ------------------ Print Processes ------------------
void printProcesses(struct PCB* head) {
    printf("\n========================================================\n");
    printf("| PID | Arrival | Burst | Priority | Waiting | Turnaround |\n");
    printf("--------------------------------------------------------\n");

    struct PCB* temp = head;
    while (temp != NULL) {
        printf("| %3d | %7d | %5d | %8d | %7d | %10d |\n",
               temp->pId,
               temp->arrival_time,
               temp->burst_time,
               temp->priority,
               temp->waiting_time,
               temp->turnarround_time);
        temp = temp->next;
    }
    printf("========================================================\n");
}

// ------------------ Sort Processes by Arrival ------------------

void processes_sort(struct PCB* head){
    struct PCB* i = head;
    struct PCB* j = head;

    while(i!= NULL){
        while(j->next != NULL){
            if(j ->arrival_time > j->next->arrival_time){
                int tempInt;
                tempInt = j->pId; j->pId = j->next->pId; j->next->pId = tempInt;
                tempInt = j->arrival_time; j->arrival_time = j->next->arrival_time; j->next->arrival_time = tempInt;
                tempInt = j->burst_time; j->burst_time = j->next->burst_time; j->next->burst_time = tempInt;
                tempInt = j->priority; j->priority = j->next->priority; j->next->priority = tempInt;
                tempInt = j->waiting_time; j->waiting_time = j->next->waiting_time; j->next->waiting_time = tempInt;
                tempInt = j->turnarround_time; j->turnarround_time = j->next->turnarround_time; j->next->turnarround_time = tempInt;
            }
            j = j->next;
        }
        i = i->next;
    }
}


// ------------------ FCFS Algorithm ------------------
void FCFS(struct PCB* head) {
    processes_sort(head);

    int cur_time = 0;
    struct PCB* temp = head;

    while(temp != NULL) {
        if (temp->arrival_time > cur_time)
            cur_time = temp->arrival_time;

        temp->waiting_time = cur_time - temp->arrival_time;
        temp->turnarround_time = temp->burst_time + temp->waiting_time;

        cur_time += temp->burst_time;
        temp = temp->next;
    }
}
