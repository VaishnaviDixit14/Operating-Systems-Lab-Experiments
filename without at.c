#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct process {
    int pid;        // Process ID
    int burstTime;  // Burst Time
    int remainingTime;  // Remaining Burst Time
};

int main() {
    struct process processes[MAX_PROCESSES];
    int n, i, quantum, totalBurstTime = 0, waitingTime = 0, turnaroundTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter quantum: ");
    scanf("%d", &quantum);

    // Input Process details
    for(i=0; i<n; i++) {
        printf("\nProcess %d\n", i+1);
        printf("Enter Burst Time: ");
        scanf("%d", &processes[i].burstTime);
        processes[i].pid = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
        totalBurstTime += processes[i].burstTime;
    }

    int currentTime = 0;
    while(totalBurstTime > 0) {
        for(i=0; i<n; i++) {
            // If process has not completed
            if(processes[i].remainingTime > 0) {
                printf("Executing process %d at time %d\n", processes[i].pid, currentTime);
                if(processes[i].remainingTime <= quantum) {
                    totalBurstTime -= processes[i].remainingTime;
                    turnaroundTime += currentTime + processes[i].remainingTime - processes[i].burstTime;
                    waitingTime += currentTime - processes[i].burstTime;
                    currentTime += processes[i].remainingTime;
                    processes[i].remainingTime = 0;
                } else {
                    totalBurstTime -= quantum;
                    processes[i].remainingTime -= quantum;
                    currentTime += quantum;
                }
            }
        }
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)waitingTime/n);
    printf("Average Turnaround Time: %.2f\n", (float)turnaroundTime/n);

    return 0;
}
