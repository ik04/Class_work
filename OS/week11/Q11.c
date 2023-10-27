#include <stdio.h>
#include <limits.h>

#define MAX_BLOCKS 100

// Structure to represent a memory block
struct MemoryBlock {
    int size;
    int allocated;  // 0 for unallocated, 1 for allocated
};

// Function prototypes
void initializeMemory(struct MemoryBlock memory[], int size);
void displayMemory(struct MemoryBlock memory[], int size);
int firstFit(struct MemoryBlock memory[], int size, int processSize);
int bestFit(struct MemoryBlock memory[], int size, int processSize);
int worstFit(struct MemoryBlock memory[], int size, int processSize);

int main() {
    struct MemoryBlock memory[MAX_BLOCKS];
    int memorySize, processSize, choice, index;

    printf("Enter the total size of memory: ");
    scanf("%d", &memorySize);

    initializeMemory(memory, memorySize);

    do {
        printf("\nMemory Allocation Techniques\n");
        printf("1. First Fit\n");
        printf("2. Best Fit\n");
        printf("3. Worst Fit\n");
        printf("4. Display Memory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter process size: ");
                scanf("%d", &processSize);
                index = firstFit(memory, memorySize, processSize);
                break;
            case 2:
                printf("Enter process size: ");
                scanf("%d", &processSize);
                index = bestFit(memory, memorySize, processSize);
                break;
            case 3:
                printf("Enter process size: ");
                scanf("%d", &processSize);
                index = worstFit(memory, memorySize, processSize);
                break;
            case 4:
                displayMemory(memory, memorySize);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to initialize memory blocks
void initializeMemory(struct MemoryBlock memory[], int size) {
    for (int i = 0; i < size; i++) {
        memory[i].size = 0;
        memory[i].allocated = 0;
    }
}

// Function to display the current state of memory
void displayMemory(struct MemoryBlock memory[], int size) {
    printf("\nMemory Status:\n");
    for (int i = 0; i < size; i++) {
        printf("Block %d: Size = %d, Allocated = %s\n", i + 1, memory[i].size,
               memory[i].allocated ? "Yes" : "No");
    }
}

// First Fit Algorithm
int firstFit(struct MemoryBlock memory[], int size, int processSize) {
    for (int i = 0; i < size; i++) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            memory[i].allocated = 1;
            printf("Memory allocated at Block %d using First Fit.\n", i + 1);
            return i;
        }
    }
    printf("Memory allocation failed using First Fit.\n");
    return -1;
}

// Best Fit Algorithm
int bestFit(struct MemoryBlock memory[], int size, int processSize) {
    int bestFitIndex = -1;
    int bestFitSize = INT_MAX;

    for (int i = 0; i < size; i++) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            if (memory[i].size < bestFitSize) {
                bestFitSize = memory[i].size;
                bestFitIndex = i;
            }
        }
    }

    if (bestFitIndex != -1) {
        memory[bestFitIndex].allocated = 1;
        printf("Memory allocated at Block %d using Best Fit.\n", bestFitIndex + 1);
    } else {
        printf("Memory allocation failed using Best Fit.\n");
    }

    return bestFitIndex;
}

// Worst Fit Algorithm
int worstFit(struct MemoryBlock memory[], int size, int processSize) {
    int worstFitIndex = -1;
    int worstFitSize = -1;

    for (int i = 0; i < size; i++) {
        if (!memory[i].allocated && memory[i].size >= processSize) {
            if (memory[i].size > worstFitSize) {
                worstFitSize = memory[i].size;
                worstFitIndex = i;
            }
        }
    }

    if (worstFitIndex != -1) {
        memory[worstFitIndex].allocated = 1;
        printf("Memory allocated at Block %d using Worst Fit.\n", worstFitIndex + 1);
    } else {
        printf("Memory allocation failed using Worst Fit.\n");
    }

    return worstFitIndex;
}
