#include <stdio.h>
#include <unistd.h>

int main() {
    int pid, n, oddsum = 0, evensum = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    pid = fork();
    
    if (pid == 0) {
        // Child process calculates the sum of odd numbers
        for (int i = 1; i <= n; i += 2) {
            oddsum += i;
        }
        printf("Sum of odd numbers: %d\n", oddsum);
    } else {
        // Parent process calculates the sum of even numbers
        for (int i = 2; i <= n; i += 2) {
            evensum += i;
        }
        wait(NULL); // Wait for the child process to finish
        printf("Sum of even numbers: %d\n", evensum);
    }
    return 0;
}
