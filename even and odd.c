//Q3) Write a c program to check the given number is even number using parent process if not print a odd number using child process. 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int num, result;
    pid_t pid;

    printf("Enter a number: ");
    scanf("%d", &num);

    pid = fork();

    if (pid == -1) {
        printf("Error: Failed to create child process!\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        if (num % 2 != 0) {
            printf("%d is an odd number and child pid:%d\n", num,getpid());
        }
    } else {
        // Parent process
  
        if (num % 2 == 0) {
            printf("%d is an even number and parent pid:%d\n", num, getppid());
        }
    }

    return 0;
}

