#include <stdio.h>

#define MAX_BLOCKS 5
#define MAX_PROCESSES 4

int memory_blocks[MAX_BLOCKS] = {100, 500, 200, 300, 600};
int processes[MAX_PROCESSES] = {212, 417, 112, 426};
int allocation[MAX_PROCESSES];

void first_fit() {
    for (int i = 0; i < MAX_PROCESSES; ++i) {
        for (int j = 0; j < MAX_BLOCKS; ++j) {
            if (memory_blocks[j] >= processes[i]) {
                allocation[i] = j;
                memory_blocks[j] -= processes[i];
                break;
            }
        }
    }

    // Print allocation
    for (int i = 0; i < MAX_PROCESSES; ++i) {
        printf("Process %d allocated to Block %d\n", i + 1, allocation[i] + 1);
    }
}

void best_fit() {
    for (int i = 0; i < MAX_PROCESSES; ++i) {
        int best_fit_index = -1;
        for (int j = 0; j < MAX_BLOCKS; ++j) {
            if (memory_blocks[j] >= processes[i]) {
                if (best_fit_index == -1 || memory_blocks[j] < memory_blocks[best_fit_index]) {
                    best_fit_index = j;
                }
            }
        }

        if (best_fit_index != -1) {
            allocation[i] = best_fit_index;
            memory_blocks[best_fit_index] -= processes[i];
        }
    }

    // Print allocation
    for (int i = 0; i < MAX_PROCESSES; ++i) {
        printf("Process %d allocated to Block %d\n", i + 1, allocation[i] + 1);
    }
}

void worst_fit() {
    for (int i = 0; i < MAX_PROCESSES; ++i) {
        int worst_fit_index = -1;
        for (int j = 0; j < MAX_BLOCKS; ++j) {
            if (memory_blocks[j] >= processes[i]) {
                if (worst_fit_index == -1 || memory_blocks[j] > memory_blocks[worst_fit_index]) {
                    worst_fit_index = j;
                }
            }
        }

        if (worst_fit_index != -1) {
            allocation[i] = worst_fit_index;
            memory_blocks[worst_fit_index] -= processes[i];
        }
    }

    // Print allocation
    for (int i = 0; i < MAX_PROCESSES; ++i) {
        printf("Process %d allocated to Block %d\n", i + 1, allocation[i] + 1);
    }
}

int main() {
    printf("First Fit Allocation:\n");
    first_fit();

    printf("\nBest Fit Allocation:\n");
    best_fit();

    printf("\nWorst Fit Allocation:\n");
    worst_fit();

    return 0;
}
