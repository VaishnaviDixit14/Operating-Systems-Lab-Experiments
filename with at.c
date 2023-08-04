#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct process {
    int pid;        // Process ID
    int burstTime;  // Burst Time
    int arrivalTime;// Arrival Time
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
        printf("Enter Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        processes[i].pid = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
        totalBurstTime += processes[i].burstTime;
    }

    // Sort processes based on Arrival Time
    for(i=0;i<n-1;i++){
        int j;
        for(j=i+1;j<n;j++){
            if(processes[i].arrivalTime>processes[j].arrivalTime){
                struct process temp=processes[i];
                processes[i]=processes[j];
                processes[j]=temp;
            }
        }
    }

    int currentTime = 0;
    while(totalBurstTime > 0) {
        for(i=0; i<n; i++) {
            // If process has arrived and not completed
            if(processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                if(processes[i].remainingTime <= quantum) {
                    totalBurstTime -= processes[i].remainingTime;
                    turnaroundTime += currentTime + processes[i].remainingTime - processes[i].arrivalTime;
                    waitingTime += currentTime - processes[i].arrivalTime;
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

