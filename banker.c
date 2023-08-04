// Consider a system where there are set of process running in the system and a set of resources are available for completing the execution of processess. Assume you have currently four resources  with multiple 
// instances and five processess that makes use of these resources. All these processess have submitted the maximum weight of request before the start of their execution. 
// Initially some set of resources are allocated to all the processess and they request for the remaining resource in future. Write a program in C to implement the 
// Banker's Algorithm for allocating the resources to all these processess without allowing the system to enter into deadlock state. Display the following on the screen:

//(1) Allocation Matrix
//(2) Max Matrix
//(3) Need Matrix 
//(4) Available Vector and the Safe sequence

#include<stdio.h>
#define MAX_PROCESS 5
#define MAX_RESOURCES 4

void displayMatrix(int matrix[MAX_PROCESS][MAX_RESOURCES], int rows, int columns) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void displayVector(int vector[MAX_RESOURCES], int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}

int isSafeState(int available[], int max[][MAX_RESOURCES], int allocation[][MAX_RESOURCES], int need[][MAX_RESOURCES], int safeSequence[]) {
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESS] = {0};
    int count = 0;

    // Initialize work vector with available resources
    for (int i = 0; i < MAX_RESOURCES; i++) {
        work[i] = available[i];
    }

    while (count < MAX_PROCESS) {
        int found = 0;
        for (int i = 0; i < MAX_PROCESS; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < MAX_RESOURCES; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == MAX_RESOURCES) {
                    // Process i can complete its execution
                    for (int k = 0; k < MAX_RESOURCES; k++) {
                        work[k] += allocation[i][k];
                    }
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            // System is in an unsafe state
            return 0;
        }
    }

    // System is in a safe state
    return 1;
}

int main() {
    int max[MAX_PROCESS][MAX_RESOURCES];
    int allocation[MAX_PROCESS][MAX_RESOURCES];
    int need[MAX_PROCESS][MAX_RESOURCES];
    int available[MAX_RESOURCES];
    int safeSequence[MAX_PROCESS];

    printf("Enter the maximum resource matrix:\n");
    for (int i = 0; i < MAX_PROCESS; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < MAX_PROCESS; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the available vector:\n");
    for (int i = 0; i < MAX_RESOURCES; i++) {
        scanf("%d", &available[i]);
    }

    // Calculate need matrix
    for (int i = 0; i < MAX_PROCESS; i++) {
        for (int j = 0; j < MAX_RESOURCES; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    printf("\n(1) Allocation Matrix:");
    displayMatrix(allocation, MAX_PROCESS, MAX_RESOURCES);

    printf("\n(2) Max Matrix:");
    displayMatrix(max, MAX_PROCESS, MAX_RESOURCES);

    printf("\n(3) Need Matrix:");
    displayMatrix(need, MAX_PROCESS, MAX_RESOURCES);

    printf("\n(4) Available Vector:");
    displayVector(available, MAX_RESOURCES);

    if (isSafeState(available, max, allocation, need, safeSequence)) {
        printf("\nSafe sequence: ");
        for (int i = 0; i < MAX_PROCESS; i++) {
            printf("%d ", safeSequence[i]);
        }
        printf("\n");
    } else {
        printf("\nThe system is in an unsafe state. Deadlock may occur.\n");
    }

    return 0;
}
