#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork() && fork() || fork();
    fork();
    printf("Yes ");
    return 0;
}
