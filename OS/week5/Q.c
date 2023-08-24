#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 3

int je, jo, evensum = 0, sumn = 0, oddsum = 0;
int evenarr[50], oddarr[50];

void *Even(void *threadid) {
    int i, n;
    je = 0;
    n = (int)threadid;
    for (i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            evenarr[je] = i;
            evensum = evensum + i;
            je++;
        }
    }
}

void *Odd(void *threadid) {
    int i, n;
    jo = 0;
    n = (int)threadid;
    for (i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            oddarr[jo] = i;
            oddsum = oddsum + i;
            jo++;
        }
    }
}

void *SumN(void *threadid) {
    int i, n;
    n = (int)threadid;
    for (i = 1; i <= n; i++) {
        sumn = sumn + i;
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i, t;
    
    printf("Enter a number: ");
    scanf("%d", &t);
    
    pthread_create(&threads[0], NULL, Even, (void *)t);
    pthread_create(&threads[1], NULL, Odd, (void *)t);
    pthread_create(&threads[2], NULL, SumN, (void *)t);

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("The sum of first N natural numbers is %d\n", sumn);
    printf("The sum of first N even numbers is %d\n", evensum);
    printf("The sum of first N odd numbers is %d\n", oddsum);

    printf("The first N Even numbers are ----\n");
    for (i = 0; i < je; i++) {
        printf("%d ", evenarr[i]);
    }

    printf("\nThe first N Odd numbers are ----\n");
    for (i = 0; i < jo; i++) {
        printf("%d ", oddarr[i]);
    }

    pthread_exit(NULL);
}
// ! copy frm someone