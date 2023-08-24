#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t room;
sem_t chopstick[5];

void eat(int phil);

void *philosopher(void *num)
{
    int phil = *(int *)num;

    printf("Philosopher %d is thinking\n", phil);
    sleep(1); // Thinking

    sem_wait(&room);
    sem_wait(&chopstick[phil]);
    sem_wait(&chopstick[(phil + 1) % 5]);

    eat(phil);

    sem_post(&chopstick[(phil + 1) % 5]);
    sem_post(&chopstick[phil]);
    sem_post(&room);

    printf("Philosopher %d finished eating\n", phil);

    pthread_exit(NULL);
}

void eat(int phil)
{
    printf("Philosopher %d is eating\n", phil);
    sleep(2); // Eating
}

int main()
{
    int i, a[5];
    pthread_t tid[5];
    sem_init(&room, 0, 4);
    for (i = 0; i < 5; i++)
        sem_init(&chopstick[i], 0, 1);
    for (i = 0; i < 5; i++)
    {
        a[i] = i;
        pthread_create(&tid[i], NULL, philosopher, (void *)&a[i]);
    }
    for (i = 0; i < 5; i++)
        pthread_join(tid[i], NULL);

    sem_destroy(&room);
    for (i = 0; i < 5; i++)
        sem_destroy(&chopstick[i]);

    return 0;
}
