#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int pid, semid, val;
    struct sembuf sop;

    semid = semget((key_t)6, 1, IPC_CREAT | 0666);
    pid = fork();

    sop.sem_num = 0;
    sop.sem_op = 0;
    sop.sem_flg = 0;

    if (pid != 0) {
        sleep(1);
        printf("The Parent waits for WAIT signal\n");
        semop(semid, &sop, 1);
        printf("The Parent WAKED UP & doing her job\n");
        sleep(10);
        printf("Parent Over\n");
    } else {
        printf("The Child sets WAIT signal & doing her job\n");
        semctl(semid, 0, SETVAL, 1);
        sleep(10);
        printf("The Child sets WAKE signal & finished her job\n");
        semctl(semid, 0, SETVAL, 0);
        printf("Child Over\n");
    }
    return 0;
}
