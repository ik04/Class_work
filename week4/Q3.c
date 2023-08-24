#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();
    fork();
    printf("SRMIST\n");
    return 0;
}
// 8