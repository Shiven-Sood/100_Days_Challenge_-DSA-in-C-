#include <stdio.h>
#include <stdlib.h>

// structure to store car data
typedef struct {
    int position;
    int speed;
} Car;

// comparator: sort by position descending
int cmp(const void* a, const void* b) {
    Car* c1 = (Car*)a;
    Car* c2 = (Car*)b;
    return c2->position - c1->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];

    // combine data
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // sort by position descending
    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    float prevTime = 0.0;

    for (int i = 0; i < n; i++) {
        float time = (float)(target - cars[i].position) / cars[i].speed;

        // if current car takes more time → new fleet
        if (time > prevTime) {
            fleets++;
            prevTime = time;
        }
    }

    return fleets;
}

// Driver
int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = 5;

    int result = carFleet(target, position, speed, n);

    printf("Number of car fleets: %d\n", result);

    return 0;
}
