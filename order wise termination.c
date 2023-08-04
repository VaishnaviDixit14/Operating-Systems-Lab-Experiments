// write a c program to illustrate the process termination mechanism. Create 5 processes where, 1 process is a parent process and remaining 4 child processes. After execution all the processes should terminate in the following sequence 1) the parent process should terminate atlast after all the child processes terminate. 2) The 4th child process terminates last but before the parent process, The 1st child process terminates after the 3rd child process. 3) The second child process terminates before the 1st child process and after the 3rd child process.4) The 3rd child process should terminate first.
// print the sequence of termination of all the processes with their process id on the screen.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid[5];
    int status;
    // Parent process code
    printf("Parent (pid %d) \n", getppid());

    // Create 4 child processes
    for (int i = 0; i < 4; i++) {
        pid[i] = fork();
        if (pid[i] == -1) {
            perror("fork");
            exit(1);
        } else if (pid[i] == 0) {
            // Child process code
            printf("Child %d (pid %d) is running\n", i+1, getpid());
            sleep(2*(i+1));
       
            exit(0);
        }
    }

    
    // Wait for 3rd child process to terminate first
    waitpid(pid[2], &status, 0);
    printf("Child 3 (pid %d) has terminated\n", pid[2]);

    // Wait for 2nd child process to terminate second
    waitpid(pid[1], &status, 0);
    printf("Child 2 (pid %d) has terminated\n", pid[1]);

    // Wait for 1st and 4th child processes to terminate third
    waitpid(pid[0], &status, 0);
    printf("Child 1 (pid %d) has terminated\n", pid[0]);
    waitpid(pid[3], &status, 0);
    printf("Child 4 (pid %d) has terminated\n", pid[3]);
    

    // Finally, parent process terminates
    printf("Parent (pid %d) is terminated\n", getppid());
    return 0;
}

