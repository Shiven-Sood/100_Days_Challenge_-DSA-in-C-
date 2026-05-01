#include <stdio.h>
#include <stdlib.h>

// Min Heap structure
typedef struct {
    int* arr;
    int size;
} MinHeap;

// Swap
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify up
void heapifyUp(MinHeap* heap, int i) {
    while (i > 0 && heap->arr[(i - 1) / 2] > heap->arr[i]) {
        swap(&heap->arr[i], &heap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(MinHeap* heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;

    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap->arr[i], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

// Insert into heap
void insertHeap(MinHeap* heap, int val) {
    heap->arr[heap->size] = val;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

// Extract min
int extractMin(MinHeap* heap) {
    int root = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return root;
}

// Compare for qsort (sort by start time)
int cmp(const void* a, const void* b) {
    int* x = (int*)a;
    int* y = (int*)b;
    return x[0] - y[0];
}

// Main logic
int minMeetingRooms(int intervals[][2], int n) {
    qsort(intervals, n, sizeof(intervals[0]), cmp);

    MinHeap heap;
    heap.arr = (int*)malloc(n * sizeof(int));
    heap.size = 0;

    insertHeap(&heap, intervals[0][1]);

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] >= heap.arr[0]) {
            extractMin(&heap); // reuse room
        }
        insertHeap(&heap, intervals[i][1]);
    }

    return heap.size;
}

// Driver
int main() {
    int intervals[][2] = {{0, 30}, {5, 10}, {15, 20}};
    int n = sizeof(intervals) / sizeof(intervals[0]);

    int rooms = minMeetingRooms(intervals, n);

    printf("Minimum meeting rooms required: %d\n", rooms);

    return 0;
}
