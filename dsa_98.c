#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort (sort by start time)
int cmp(const void* a, const void* b) {
    int* x = (int*)a;
    int* y = (int*)b;
    return x[0] - y[0];
}

// Function to merge intervals
void mergeIntervals(int intervals[][2], int n) {
    if (n == 0) return;

    // Step 1: Sort intervals by start time
    qsort(intervals, n, sizeof(intervals[0]), cmp);

    // Step 2: Merge
    int start = intervals[0][0];
    int end = intervals[0][1];

    printf("Merged intervals:\n");

    for (int i = 1; i < n; i++) {
        // Overlapping case
        if (intervals[i][0] <= end) {
            if (intervals[i][1] > end)
                end = intervals[i][1];
        } else {
            // No overlap → print previous interval
            printf("[%d, %d]\n", start, end);
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    // Print last interval
    printf("[%d, %d]\n", start, end);
}

// Driver
int main() {
    int intervals[][2] = {{1,3}, {2,6}, {8,10}, {15,18}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    mergeIntervals(intervals, n);

    return 0;
}
