#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        printf("In Child Process\n");
        printf("Parent Process ID: %d\n", getppid());
        printf("Child Process ID: %d\n", getpid());
    } else {
        wait(NULL); // Wait for the child process to finish
        printf("In Parent Process\n");
        printf("Parent Process ID: %d\n", getpid());
        printf("Child Process ID: %d\n", pid);
    }
    return 0;
}
