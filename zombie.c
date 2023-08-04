//write a c program to show that how a child process becomes a zombie processs.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid == 0) { // child process
        printf("Child process (pid=%d) started\n", getpid());
        sleep(5); // simulate some work
        printf("Child process (pid=%d) finished\n", getpid());
        exit(0); // child process exits
    } else if (child_pid > 0) { // parent process
        printf("Parent process (pid=%d) created child process (pid=%d)\n", getpid(), child_pid);
        sleep(1); // give child process time to finish
        printf("Parent process (pid=%d) exiting\n", getpid());
        system("ps -e -o pid,ppid,state,cmd | grep Z"); // check for zombie processes
        exit(0); // parent process exits
    } else { // error creating child process
        perror("fork");
        exit(1);
    }

    return 0;
}

