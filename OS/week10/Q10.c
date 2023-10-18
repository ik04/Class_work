#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int available_resources[MAX_RESOURCES];
int maximum_claim[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];

int is_safe_state(int process, int request[]) {
    // Check if the request can be granted
    for (int i = 0; i < MAX_RESOURCES; ++i) {
        if (request[i] > need[process][i] || request[i] > available_resources[i]) {
            return 0; // Request cannot be granted
        }
    }

    // Simulate resource allocation
    for (int i = 0; i < MAX_RESOURCES; ++i) {
        available_resources[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }

    // Check if the system is in a safe state
    if (is_safe()) {
        return 1; // Request granted
    } else {
        // Rollback if not in a safe state
        for (int i = 0; i < MAX_RESOURCES; ++i) {
            available_resources[i] += request[i];
            allocation[process][i] -= request[i];
            need[process][i] += request[i];
        }
        return 0; // Request denied
    }
}

int is_safe() {
    // Implement logic to check if the system is in a safe state using Banker's Algorithm
    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};

    // Initialize work and finish arrays
    for (int i = 0; i < MAX_RESOURCES; ++i) {
        work[i] = available_resources[i];
    }

    // Find an index i such that both finish[i] is false and need[i] <= work
    int count = 0;
    while (count < MAX_PROCESSES) {
        int found = 0;
        for (int i = 0; i < MAX_PROCESSES; ++i) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < MAX_RESOURCES; ++j) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }

                if (j == MAX_RESOURCES) {
                    // Process can finish
                    for (int k = 0; k < MAX_RESOURCES; ++k) {
                        work[k] += allocation[i][k];
                    }
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }

        if (!found) {
            break; // System is not in a safe state
        }
    }

    return count == MAX_PROCESSES; // System is in a safe state if all processes finish
}

int main() {
    // Initialize available resources, maximum claim matrix, allocation matrix, and need matrix
    // ...

    // Example usage
    int process = 1;
    int request[MAX_RESOURCES] = {1, 0, 2};
    if (is_safe_state(process, request)) {
        printf("Request granted. System is in a safe state.\n");
    } else {
        printf("Request denied. System will not be in a safe state.\n");
    }

    return 0;
}
