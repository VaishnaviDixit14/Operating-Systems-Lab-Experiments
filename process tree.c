//Q2) Write a c program to create the given below process tree.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main() {
    printf("Process P0 (main) created with pid %d and parent pid %d\n", getpid(), getppid());
    
    pid_t pidP1, pidP2, pidP3, pidP4, pidP5, pidP6, pidP7;

    // create process P1
    pidP1 = fork();

    if (pidP1 == -1) {
        printf("Error: Failed to create process A!\n");
        exit(1);
    } else if (pidP1 == 0) {
        // this is process P1
        printf("Process P1 created with pid %d and parent pid %d\n", getpid(), getppid());

        // create process P3
        pidP3 = fork();

        if (pidP3 == -1) {
            printf("Error: Failed to create process C!\n");
            exit(1);
        } else if (pidP3 == 0) {
            // this is process P3
            printf("Process P3 created with pid %d and parent pid %d\n", getpid(), getppid());
            // create process P7
            pidP7 = fork();
            if (pidP7 == -1) {
            printf("Error: Failed to create process C!\n");
            exit(1);
            } else if (pidP7 == 0) {
            // this is process P7
            printf("Process P7 created with pid %d and parent pid %d\n", getpid(), getppid());
            
            exit(0);
        }
            exit(0);
        }

        // create process P6
        pidP6 = fork();

        if (pidP6 == -1) {
            printf("Error: Failed to create process D!\n");
            exit(1);
        } else if (pidP6 == 0) {
            // this is process P6
            printf("Process P6 created with pid %d and parent pid %d\n", getpid(), getppid());
            exit(0);
        }

        exit(0);
    }

    // create process P2
    pidP2 = fork();

    if (pidP2 == -1) {
        printf("Error: Failed to create process B!\n");
        exit(1);
    } else if (pidP2 == 0) {
        // this is process P2
        printf("Process P2 created with pid %d and parent pid %d\n", getpid(), getppid());

        // create process P5
        pidP5 = fork();

        if (pidP5 == -1) {
            printf("Error: Failed to create process E!\n");
            exit(1);
        } else if (pidP5 == 0) {
            // this is process P5
            printf("Process P5 created with pid %d and parent pid %d\n", getpid(), getppid());
            exit(0);
        }       
        exit(0);
    }
// create process P4
    pidP4 = fork();

    if (pidP4 == -1) {
        printf("Error: Failed to create process B!\n");
        exit(1);
    } else if (pidP4 == 0) {
        // this is process P4
        printf("Process P4 created with pid %d and parent pid %d\n", getpid(), getppid());       
        exit(0);
    }
    printf("       P0\n");
    printf("     / \\  \\\n");
    printf("    p1  P4  P2\n");
    printf("   / \\      \\\n");
    printf("  P3  P6      P5\n");
    printf("  /              \n");
    printf(" P7               \n");
    return 0;
}

