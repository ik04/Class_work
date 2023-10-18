#include <stdio.h>

#define MAX_FRAMES 3
#define MAX_REFERENCES 10

int page_frames[MAX_FRAMES];
int page_reference_sequence[MAX_REFERENCES] = {0, 1, 2, 0, 3, 0, 4, 2, 3, 0};

void fifo() {
    int front = 0, rear = 0;
    int page_faults = 0;

    for (int i = 0; i < MAX_FRAMES; ++i) {
        page_frames[i] = -1; // Initialize page frames with -1
    }

    for (int i = 0; i < MAX_REFERENCES; ++i) {
        int page = page_reference_sequence[i];
        int page_found = 0;

        for (int j = 0; j < MAX_FRAMES; ++j) {
            if (page_frames[j] == page) {
                page_found = 1;
                break;
            }
        }

        if (!page_found) {
            // Page fault, replace the front of the queue
            page_frames[front] = page;
            front = (front + 1) % MAX_FRAMES;
            rear = (rear + 1) % MAX_FRAMES;
            page_faults++;
        }
    }

    printf("Page Faults (FIFO): %d\n", page_faults);
}

void lru() {
    int page_faults = 0;
    int time[MAX_FRAMES];
    int least_recently_used = 0;

    for (int i = 0; i < MAX_FRAMES; ++i) {
        page_frames[i] = -1; // Initialize page frames with -1
        time[i] = 0;         // Initialize time array
    }

    for (int i = 0; i < MAX_REFERENCES; ++i) {
        int page = page_reference_sequence[i];
        int page_found = 0;

        for (int j = 0; j < MAX_FRAMES; ++j) {
            if (page_frames[j] == page) {
                page_found = 1;
                time[j] = i + 1; // Update time of last use
                break;
            }
        }

        if (!page_found) {
            // Page fault, replace the least recently used page
            least_recently_used = 0;
            for (int j = 1; j < MAX_FRAMES; ++j) {
                if (time[j] < time[least_recently_used]) {
                    least_recently_used = j;
                }
            }

            page_frames[least_recently_used] = page;
            time[least_recently_used] = i + 1;
            page_faults++;
        }
    }

    printf("Page Faults (LRU): %d\n", page_faults);
}

void lfu() {
    int page_faults = 0;
    int frequency[MAX_FRAMES] = {0};

    for (int i = 0; i < MAX_FRAMES; ++i) {
        page_frames[i] = -1; // Initialize page frames with -1
    }

    for (int i = 0; i < MAX_REFERENCES; ++i) {
        int page = page_reference_sequence[i];
        int page_found = 0;

        for (int j = 0; j < MAX_FRAMES; ++j) {
            if (page_frames[j] == page) {
                page_found = 1;
                frequency[j]++;
                break;
            }
        }

        if (!page_found) {
            // Page fault, replace the least frequently used page
            int least_frequent = 0;
            for (int j = 1; j < MAX_FRAMES; ++j) {
                if (frequency[j] < frequency[least_frequent]) {
                    least_frequent = j;
                }
            }

            page_frames[least_frequent] = page;
            frequency[least_frequent] = 1;
            page_faults++;
        }
    }

    printf("Page Faults (LFU): %d\n", page_faults);
}

int main() {
    printf("FIFO Page Replacement:\n");
    fifo();

    printf("\nLRU Page Replacement:\n");
    lru();

    printf("\nLFU Page Replacement:\n");
    lfu();

    return 0;
}
