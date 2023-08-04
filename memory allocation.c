// Write a program in C to implement all the dynamic memory allocation algorithm. Display the allocation of the processess into the memory partitions for all the algorithms separately.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_PARTITIONS 10
#define MAX_PROCESSES 10

// Structure to represent a memory partition
typedef struct
{
    int start_address;
    int end_address;
    int process_id;
    int allocated;
} Partition;

// Structure to represent a process
typedef struct
{
    int process_id;
    int size;
    int allocated_partition;
} Process;

// Function prototypes
void firstFit(Partition partitions[], int num_partitions, Process processes[], int num_processes);
void bestFit(Partition partitions[], int num_partitions, Process processes[], int num_processes);
void worstFit(Partition partitions[], int num_partitions, Process processes[], int num_processes);
void displayMemoryPartitions(Partition partitions[], int num_partitions);

int main()
{
    Partition partitions[MAX_PARTITIONS];
    Process processes[MAX_PROCESSES];
    int num_partitions, num_processes;

    printf("Enter the number of memory partitions: ");
    scanf("%d", &num_partitions);

    printf("Enter the details of memory partitions:\n");
    for (int i = 0; i < num_partitions; i++)
    {
        printf("Partition %d:\n", i + 1);
        printf("Start Address: ");
        scanf("%d", &partitions[i].start_address);
        printf("End Address: ");
        scanf("%d", &partitions[i].end_address);
        partitions[i].allocated = 0;
        partitions[i].process_id = -1;
        printf("\n");
    }

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the details of processes:\n");
    for (int i = 0; i < num_processes; i++)
    {
        printf("Process %d:\n", i + 1);
        printf("Size: ");
        scanf("%d", &processes[i].size);
        processes[i].allocated_partition = -1;
        printf("\n");
    }

    printf("First Fit Algorithm:\n");
    firstFit(partitions, num_partitions, processes, num_processes);
    displayMemoryPartitions(partitions, num_partitions);
    printf("\n");

    printf("Best Fit Algorithm:\n");
    bestFit(partitions, num_partitions, processes, num_processes);
    displayMemoryPartitions(partitions, num_partitions);
    printf("\n");

    printf("Worst Fit Algorithm:\n");
    worstFit(partitions, num_partitions, processes, num_processes);
    displayMemoryPartitions(partitions, num_partitions);
    printf("\n");

    return 0;
}

void firstFit(Partition partitions[], int num_partitions, Process processes[], int num_processes)
{
    for (int i = 0; i < num_processes; i++)
    {
        for (int j = 0; j < num_partitions; j++)
        {
            if (!partitions[j].allocated && processes[i].size <= (partitions[j].end_address - partitions[j].start_address))
            {
                partitions[j].allocated = 1;
                partitions[j].process_id = processes[i].process_id;
                processes[i].allocated_partition = j;
                break;
            }
        }
    }
}

void bestFit(Partition partitions[], int num_partitions, Process processes[], int num_processes)
{
    for (int i = 0; i < num_processes; i++)
    {
        int min_index = -1;
        int min_size = INT_MAX;

        for (int j = 0; j < num_partitions; j++)
        {
            if (!partitions[j].allocated && (partitions[j].end_address - partitions[j].start_address) >= processes[i].size &&
                (partitions[j].end_address - partitions[j].start_address) < min_size)
            {
                min_size = partitions[j].end_address - partitions[j].start_address;
                min_index = j;
            }
        }

        if (min_index != -1)
        {
            partitions[min_index].allocated = 1;
            partitions[min_index].process_id = processes[i].process_id;
            processes[i].allocated_partition = min_index;
        }
    }
}
void worstFit(Partition partitions[], int num_partitions, Process processes[], int num_processes)
{
    for (int i = 0; i < num_processes; i++)
    {
        int max_index = -1;
        int max_size = INT_MIN;

        for (int j = 0; j < num_partitions; j++)
        {
            if (!partitions[j].allocated && (partitions[j].end_address - partitions[j].start_address) >= processes[i].size &&
                (partitions[j].end_address - partitions[j].start_address) > max_size)
            {
                max_size = partitions[j].end_address - partitions[j].start_address;
                max_index = j;
            }
        }

        if (max_index != -1)
        {
            partitions[max_index].allocated = 1;
            partitions[max_index].process_id = processes[i].process_id;
            processes[i].allocated_partition = max_index;
        }
    }
}

void displayMemoryPartitions(Partition partitions[], int num_partitions)
{
    printf("Memory Partitions:\n");
    for (int i = 0; i < num_partitions; i++)
    {
        printf("Partition %d: Start Address=%d, End Address=%d, Allocated Process ID=%d\n",
               i + 1, partitions[i].start_address, partitions[i].end_address, partitions[i].process_id);
    }
}
