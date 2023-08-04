
//Q1) Write a c program to create 3 child process for parent 1 and 2 child process for parent 2. Display the process id for the process.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2, pid3, pid4, pid5;

    // create first child process for parent 1
    pid1 = fork();

    if (pid1 == -1) {
        printf("Error: Failed to create first child process!\n");
        exit(1);
    } else if (pid1 == 0) {
        // this is the first class of child processes for parent 1
        printf("First child process pid %d and parent pid %d\n", getpid(), getppid());
        exit(0);
    }

    // create second child process for parent 1
    pid2 = fork();

    if (pid2 == -1) {
        printf("Error: Failed to create second child process!\n");
        exit(1);
    } else if (pid2 == 0) {
        // this is the second class of child processes for parent 1
        printf("Second child process pid %d and parent pid %d\n", getpid(), getppid());
        exit(0);
    }

    // create third child process for parent 1
    pid3 = fork();

    if (pid3 == -1) {
        printf("Error: Failed to create third child process!\n");
        exit(1);
    } else if (pid3 == 0) {
        // this is the first class of child processes for parent 1
        printf("Third child process pid %d and parent pid %d\n", getpid(), getppid());
        exit(0);
    }

    // create first child process for parent 2
    pid4 = fork();

    if (pid4 == -1) {
        printf("Error: Failed to create first child process for parent 2!\n");
        exit(1);
    } else if (pid4 == 0) {
        // this is the only class of child processes for parent 2
        printf("First child process pid %d and parent pid %d\n", getpid(), getppid());
        exit(0);
    }

    // create second child process for parent 2
    pid5 = fork();

    if (pid5 == -1) {
        printf("Error: Failed to create second child process for parent 2!\n");
        exit(1);
    } else if (pid5 == 0) {
        // this is the only class of child processes for parent 2
        printf("Second child process pid %d and parent pid %d\n", getpid(), getppid());
        exit(0);
    }

    printf("All child processes have completed.\n");

    return 0;
}

