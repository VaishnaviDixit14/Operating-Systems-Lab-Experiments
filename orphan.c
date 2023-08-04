//write a c program to show when a child process becomes an orphan process

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
        sleep(1); // give child process time to start
        printf("Parent process (pid=%d) exiting\n", getpid());
        system("ps -o pid,ppid,state,cmd | grep a.out"); // check parent process ID of child process
        exit(0); // parent process exits
    } else { // error creating child process
        perror("fork");
        exit(1);
    }

    return 0;
}

